/*
 * Copyright (c) 2015 Intel Corporation.  All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.

 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef _BLE_DESCRIPTOR_H_INCLUDED
#define _BLE_DESCRIPTOR_H_INCLUDED

#include "BleAttribute.h"

/**
 * BLE GATT Descriptor class
 */
class BleDescriptor : public BleAttribute {
public:
    /**
     * Constructor for BLE Descriptor
     *
     * @param uuid        16-bit UUID (in string form) defined by BLE standard
     * @param value       Value of descriptor, as a byte array.  Data is stored in internal copy.
     * @param valueLength Data length required for descriptor value (<= BLE_MAX_ATTR_DATA_LEN)
     */
    BleDescriptor(const char* uuid, const uint8_t value[], uint16_t valueLength);

    /**
     * Constructor for BLE Descriptor
     *
     * @param uuid        16-bit UUID (in string form) defined by BLE standard
     * @param value       String value of descriptor.  Data is stored in internal copy. 
     *                    (String length <= BLE_MAX_ATTR_DATA_LEN)
     */
    BleDescriptor(const char* uuid, const char* value);

    /**
     * Get data pointer to the value of the Descriptor
     *
     * @return const uint8_t* pointer to the value of the Descriptor
     */
    const uint8_t* value(void) const;

    /**
     * Get the length of the value of the Descriptor
     *
     * @return uint16_t size of Descriptor value in bytes
     */
    uint16_t valueLength(void) const;


    uint8_t operator[] (int offset) const;

protected:
    BleStatus add(uint16_t serviceHandle);

    friend BlePeripheral;

private:
    uint8_t _data[BLE_MAX_ATTR_DATA_LEN];
    uint16_t _data_len;
};

#endif // _BLE_DESCRIPTOR_H_INCLUDED
