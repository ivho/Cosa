/**
 * @file Cosa/Fai.h
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2012, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 *
 * @section Description
 * The Cosa Ciao data stream of Arduino state (Cosa fai).
 *
 * This file is part of the Arduino Che Cosa project.
 */

#ifndef __COSA_FAI_H__
#define __COSA_FAI_H__

#include "Cosa/Ciao.h"
#include "Cosa/Pins.h"

class Fai : public Ciao {
public:

  /**
   * Cosa fai: data type descriptors and prototypes.
   */
  class Descriptor {
  public:
    enum {
      ANALOG_PIN_ID = 0x10,
      DIGITAL_PIN_ID = 0x11,
      DIGITAL_PINS_ID = 0x12,
      SAMPLE_REQUEST_ID = 0x20,
      SET_MODE_ID = 0x21
    };
    static const Ciao::Descriptor::user_t analog_pin_t PROGMEM;
    static const Ciao::Descriptor::user_t digital_pin_t PROGMEM;
    static const Ciao::Descriptor::user_t digital_pins_t PROGMEM;
    static const Ciao::Descriptor::user_t sample_request_t PROGMEM;
  };

  /**
   * Stream analog pin value. The identity code is ANALOG_PIN_ID(0x10).
   */
  struct analog_pin_t {
    uint8_t pin;
    uint16_t value;
  };

  /**
   * Stream digital pin value. The identity code is DIGITAL_PIN_ID(0x11).
   */
  struct digital_pin_t {
    uint8_t pin;
    uint8_t value;
  };

  /**
   * Stream digital pins value. The identity code is DIGITAL_PINS_ID(0x12).
   */
  struct digital_pins_t {
    uint16_t pins;
    uint16_t values;
  };

  /**
   * Stream sample request. The identity code is SAMPLE_ID(0x20).
   */
  struct sample_request_t {
    uint32_t pins;
    uint16_t period;
  };

  /**
   * Construct data streaming for given device.
   * @param[in] dev output device.
   */
  Fai(IOStream::Device* dev = 0) : Ciao(dev) {}

  /**
   * Write digital pin value to data stream.
   * @param[in] pin to write to data stream.
   */
  void write(Pin* pin);

  /**
   * Write analog pin value to data stream.
   * @param[in] pin to write to data stream.
   */
  void write(AnalogPin* pin);
};

#endif