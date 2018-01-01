#include <stdio.h>
#include <list.h>
#include <hash.h>
#include "filesys/file.h"
#include <stdint.h>

struct page{
	struct list_elem elem;
	void *uaddr;
	struct spte *spte_ptr;
};

struct frame{
	struct list_elem elem;
	void *kaddr;
};

struct spte{
	struct hash_elem hash_elem;
	void *uaddr;
	uint32_t *pd;
	struct swap_slot *swap_slot_ptr;
	struct frame *frame_ptr;
	struct page *page_ptr;
	struct file *file;
	off_t offset;
	uint32_t read_bytes;
	bool writable;
};

struct swap_slot{
	struct hash_elem hash_elem;
	size_t idx;
};
