package lib

import (
	"container/heap"
	"testing"
)

func Test_IntHeap(t *testing.T) {
	h := &IntHeap{2, -7, 8}
	heap.Init(h)
	heap.Push(h, 3)
	heap.Push(h, 5)
	heap.Push(h, 11)

	expect := []int{-7, 2, 3, 5, 8, 11}
	result := make([]int, 0, len(expect))
	for h.Len() > 0 {
		result = append(result, heap.Pop(h).(int))
	}

	if !IsSameIntSlice(expect, result) {
		t.Errorf("\nExpected: %v\nGot:      %v", expect, result)
	}
}

func Test_StringHeap(t *testing.T) {
	h := &StringHeap{"Hello", "", "7"}
	heap.Init(h)
	heap.Push(h, "apple")
	heap.Push(h, "Apple")
	heap.Push(h, "World!")

	expect := []string{"", "7", "Apple", "Hello", "World!", "apple"}
	result := make([]string, 0, len(expect))
	for h.Len() > 0 {
		result = append(result, heap.Pop(h).(string))
	}

	if !IsSameStringSlice(expect, result) {
		t.Errorf("\nExpected: %v\nGot:      %v", expect, result)
	}
}