////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2022 Mateusz Malinowski
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>

class I2C
{
public:
    /**
     * Basic constructor. Only initialises variables without opening serial port.
     */
    I2C();

    /**
     * Destructor closes serial port.
     */
    virtual ~I2C();

    /**
     * Opens serial port.
     *  @param device the path to the device.
     *  @return true if device was successfully opened.
     */
    bool openSerialPort(const char* device);

    /**
     * Closes serial port.
     */
    void closeSerialPort();

    /**
     * Reads a byte from the device.
     *  @param deviceAddr serial device to read data from.
     *  @param regAddr the address of the register to read.
     *  @return the read data. If failed, zero is returned (it also might be a correct value!).
     */
    uint8_t readByte(const uint8_t deviceAddr, const uint8_t regAddr) const;

    /**
     * Reads multiple bytes from the device.
     *  @param deviceAddr serial device to read data from.
     *  @param regAddr the address of the register from which the read should begin.
     *  @param length the number of bytes to read (the length of @p data).
     *  @param[out] data preallocated buffer for read data.
     */
    void readNBytes(const uint8_t deviceAddr, const uint8_t regAddr, const uint8_t length, uint8_t data[]) const;

    /**
     * Writes a byte to the device.
     *  @param deviceAddr serial device to write data to.
     *  @param regAddr the address of the register to write new data.
     *  @param value a new data to upload to the device.
     */
    void writeByte(const uint8_t deviceAddr, const uint8_t regAddr, const uint8_t value) const;

    /**
     * Writes a chunk of data to the device. The first value in @p data has to be register address.
     *  @param deviceAddr serial device to write data to.
     *  @param length the number of bytes to write (the length of @p data) including register address.
     *  @param data buffer with data to write (register address as the first value).
     */
    void writeData(const uint8_t deviceAddr, const uint8_t length, const uint8_t data[]) const;

private:
    /**
     * Connects to the device under address @p deviceAddr.
     */
    bool connectToDevice(const uint8_t deviceAddr) const;

    /** Serial port identified. */
    int mSerial;
    /** The address of currently connected device. */
    mutable uint8_t mCurrentDevice;
};
