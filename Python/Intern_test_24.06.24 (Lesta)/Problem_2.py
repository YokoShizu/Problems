"""
Примечание: я не стала приводить вывод всех реализаций к одинаковму виду, чтобы дополнительно показать особенности вывода
каждой из них. В первом и третьем случае можно привести вывод к минимализму второго, если добавить булевы маски. Для 
реализации через NumPy массив потребуется дополнительная аккуратность со сдвигом элементов при записи их в __str__().

Реализация первая: через collections.deque.

Плюсы заключаются в простоте реализации и отличной оптимизацией при возможности использовать любые типы данных: временная 
сложность операций удаления и добавления элементов в данной реализации имеет порядок O(1), в то время как реализация через 
список временная сложность порядка O(n). Основным минусом является автоматизированность поведения такой реализации: если 
потребуется каким-то образом настроить удаление элементов (например, чтобы удалялся в первую очередь не самый старый элемент), 
то придется прибегнуть к другому методу.
"""

from collections import deque

class RingBufferFIFODeque:
    def __init__(self, buffer_size):
        self.buffer = deque(maxlen = buffer_size)
    
    def append_element(self, new_item):
        self.buffer.append(new_item)
    
    def pop_element(self):
        if self.buffer:
            return self.buffer.popleft()
        else:
            raise IndexError("Error: an attempt to pop an item from an empty buffer!")
    
    def __str__(self):
        return str(self.buffer)
        
"""
Реализация вторая: через список.

Главными плюсами данной реализации являются полная свобода в управлении поведения буффера и возможность хранить одновременно любые 
типы данных. Однако эти же преимущества приводят и к недостаткам: меньшая оптимизация по сравнению с уже готовыми решениями и 
увеличение временной сложности до O(n) из-за возникновения необходимости сдвигать список при операции pop_element(0).
"""

class RingBufferFIFOList:
    def __init__(self, buffer_size):
        self.buffer_size = buffer_size
        self.buffer = [None] * buffer_size
        self.start = 0
        self.end = 0
        self.full = False
    
    def append_element(self, new_item):
        self.buffer[self.end] = new_item
        if self.full:
            self.start = (self.start + 1) % self.buffer_size
        self.end = (self.end + 1) % self.buffer_size
        self.full = self.end == self.start
    
    def pop_element(self):
        if self.empty_buffer():
            raise IndexError("Error: an attempt to pop an item from an empty buffer!")
        first_item = self.buffer[self.start]
        self.start = (self.start + 1) % self.buffer_size
        self.is_full = False
        return first_item
    
    def empty_buffer(self):
        return self.start == self.end and not self.full
    
    def __str__(self):
        if self.full:
            all_items = self.buffer[self.start:] + self.buffer[:self.end]
        elif self.start < self.end:
            all_items = self.buffer[self.start:self.end]
        else:
            all_items = self.buffer[self.start:] + self.buffer[:self.end]
        return str(all_items)
        
"""
Реализация третья: через массив (на примере целых чисел).

Основным плюсом массива является отличная оптимизация для использования конкретного типа данных. У нас все еще есть гибкость и
полная свобода в управлении поведением буффера и высокая скорость выполнения операций, если мы точно знаем, какой тип данных собираемся 
использовать. Однако вновь недостатки проистекают из преимуществ: необходимость сразу указывать тип данных может сильно ограничить 
приложения данной реализации.
"""

import array

class RingBufferFIFOArray:
    def __init__(self, buffer_size):
        self.buffer_size = buffer_size
        self.buffer = array.array('i', [0] * buffer_size)
        self.start = 0
        self.end = 0
        self.full = False
    
    def append_element(self, new_item):
        self.buffer[self.end] = new_item
        if self.full:
            self.start = (self.start + 1) % self.buffer_size
        self.end = (self.end + 1) % self.buffer_size
        self.full = self.end == self.start
    
    def pop_element(self):
        if self.empty_buffer():
            raise IndexError("Error: an attempt to pop an item from an empty buffer!")
        first_item = self.buffer[self.start]
        self.start = (self.start + 1) % self.buffer_size
        self.is_full = False
        return first_item
    
    def empty_buffer(self):
        return self.start == self.end and not self.full
    
    def __str__(self):
        if self.full:
            all_items = self.buffer[self.start:] + self.buffer[:self.end]
        elif self.start < self.end:
            all_items = self.buffer[self.start:self.end]
        else:
            all_items = self.buffer[self.start:] + self.buffer[:self.end]
        return str(all_items)
        
"""
Реализация четвертая: через массив с использованием NumPy.

NumPy позволяет, как и список, пользоваться гибкостью в хранении данных благодаря типу данных object. Кроме того операции имеют
константную сложность O(1). К минусам можно отнести необходимость пользоваться сторонней библиотекой NumPy и потенциальное снижение 
производительности из-за необходимости каждый раз проверять тип элемента.
"""

import numpy as np

class RingBufferFIFONumpy:
    def __init__(self, buffer_size):
        self.buffer_size = buffer_size
        self.buffer = np.empty(buffer_size, dtype = object)
        self.start = 0
        self.end = 0
        self.full = False

    def append_element(self, new_item):
        self.buffer[self.end] = new_item
        if self.full:
            self.start = (self.start + 1) % self.buffer_size
        self.end = (self.end + 1) % self.buffer_size
        self.full = self.end == self.start

    def pop_element(self):
        if self.empty_buffer():
            raise IndexError("Error: an attempt to pop an item from an empty buffer!")
        first_item = self.buffer[self.start]
        self.buffer[self.start] = None
        self.start = (self.start + 1) % self.buffer_size
        self.full = False
        return first_item
        
    def empty_buffer(self):
        return self.start == self.end and not self.full

    def __str__(self):
        mask = self.buffer != None
        filtered_items = self.buffer[mask]
        if self.full:
            all_items = np.concatenate((self.buffer[self.start:], self.buffer[:self.start]))
        elif self.start < self.end:
            all_items = self.buffer[self.start:self.end]
        else:
            all_items = np.concatenate((self.buffer[self.start:], self.buffer[:self.end]))
        return str(filtered_items.tolist())