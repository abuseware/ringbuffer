#pragma once
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    uint16_t size;
    uint16_t start;
    uint16_t end;
} ring_buffer_t;

ring_buffer_t* ring_buffer_create(uint16_t size);
void ring_buffer_destroy(ring_buffer_t* ring);

uint8_t ring_buffer_write(ring_buffer_t* ring, uint8_t data);
uint8_t ring_buffer_read(ring_buffer_t* ring, uint8_t *target);
