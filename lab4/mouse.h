#ifndef MOUSE_H
#define MOUSE_H

#include "i8042.h"
#include <lcom/lcf.h>
#include <stdint.h>

int(mouse_subscribe_int)(uint8_t *bit_no);

int(mouse_disable_irq)();

int(mouse_enable_irq)();

int(mouse_unsubscribe_int)();

void(mouse_ih)();

void(packet_parser)(struct packet *pp);

int(is_IBF_set)();

int(is_OBF_set)();

uint8_t(mouse_command)(uint8_t value);

int(reset_KBC_cmd_byte)();

int(mouse_polling)();

struct mouse_ev *(mouse_detect_evt)(struct packet *pp);

enum states {
  INITIAL_STATE,
  LB_PRESSED_STATE,
  FIRST_LINE_DRAWN_STATE,
  RB_PRESSED_STATE,
  FINAL_STATE
};

enum states(update_gesture_state)(struct mouse_ev *mouse_event, enum states logicalAndState, uint8_t x_len, uint8_t tolerance);

#endif