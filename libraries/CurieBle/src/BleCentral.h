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

#ifndef _BLE_CENTRAL_H_INCLUDED
#define _BLE_CENTRAL_H_INCLUDED

#include "BleCommon.h"

class BlePeripheral;

class BleCentral {
    friend class BlePeripheral;

    public:
        /**
         * Is the Central connected
         *
         * @return boolean_t true if the central is connected, otherwise false
         */
        boolean_t connected(void);

        /**
         * Get the address of the Central in string form
         *
         * @return const char* address of the Central in string form
         */
        const char* address(void) const;
        
        /**
         * Disconnect the central if it is connected
         *
         * @return BleStatus result of operation
         */
        BleStatus disconnect(void);

        /**
         * Poll the central for events
         */
        void poll(void);

        operator bool(void) const;
        boolean_t operator==(const BleCentral& rhs) const;
        boolean_t operator!=(const BleCentral& rhs) const;

    protected:
        BleCentral(BlePeripheral* peripheral);
        void setAddress(ble_addr_t address);
        void clearAddress();

    private:
        BlePeripheral* _peripheral;
        ble_addr_t     _address;
};

#endif
