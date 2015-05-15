#include <stdlib.h>

#include "ringbuffer.h"

ring_buffer_t* ring_buffer_create(uint16_t size){
    ring_buffer_t *ring = (ring_buffer_t*)malloc(sizeof(ring_buffer_t));
    ring->buffer = malloc(size);
    ring->size = size;
    ring->start = 0;
    ring->end = 0;

    return ring;
}

void ring_buffer_destroy(ring_buffer_t* ring){
    if(ring){
        free(ring->buffer);
        free(ring);
    }
}

uint8_t ring_buffer_write(ring_buffer_t* ring, uint8_t data){
    uint8_t next = (ring->end + 1) % ring->size;

    if(next == ring->start){
        return 1;
    }

    ring->buffer[ring->end] = data;

    ring->end = next;

    return 0;
}

uint8_t ring_buffer_read(ring_buffer_t* ring, uint8_t* target){
    if(ring->end == ring->start){
        return 1;
    }

    *target = ring->buffer[ring->start];

    ring->start = (ring->start + 1) % ring->size;

    return 0;
}
