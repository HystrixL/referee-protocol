#pragma once

#include <cstdint>
namespace rp::crc {

/**
 * @brief          calculate the crc8
 * @param[in]      pch_message: data
 * @param[in]      dw_length: stream length = data + checksum
 * @param[in]      ucCRC8: init CRC8
 * @retval         calculated crc8
 */
/**
 * @brief          计算CRC8
 * @param[in]      pch_message: 数据
 * @param[in]      dw_length: 数据和校验的长度
 * @param[in]      ucCRC8:初始CRC8
 * @retval         计算完的CRC8
 */
uint8_t get_CRC8_check_sum(unsigned char* pch_message, unsigned int dw_length, unsigned char ucCRC8);

/**
 * @brief          CRC8 verify function
 * @param[in]      pch_message: data
 * @param[in]      dw_length:stream length = data + checksum
 * @retval         true of false
 */
/**
 * @brief          CRC8校验函数
 * @param[in]      pch_message: 数据
 * @param[in]      dw_length: 数据和校验的长度
 * @retval         真或者假
 */
uint32_t verify_CRC8_check_sum(unsigned char* pch_message, unsigned int dw_length);

/**
 * @brief          append CRC8 to the end of data
 * @param[in]      pch_message: data
 * @param[in]      dw_length:stream length = data + checksum
 * @retval         none
 */
/**
 * @brief          添加CRC8到数据的结尾
 * @param[in]      pch_message: 数据
 * @param[in]      dw_length: 数据和校验的长度
 * @retval         none
 */
void append_CRC8_check_sum(unsigned char* pch_message, unsigned int dw_length);

/**
 * @brief          calculate the crc16
 * @param[in]      pch_message: data
 * @param[in]      dw_length: stream length = data + checksum
 * @param[in]      wCRC: init CRC16
 * @retval         calculated crc16
 */
/**
 * @brief          计算CRC16
 * @param[in]      pch_message: 数据
 * @param[in]      dw_length: 数据和校验的长度
 * @param[in]      wCRC:初始CRC16
 * @retval         计算完的CRC16
 */
uint16_t get_CRC16_check_sum(uint8_t* pch_message, uint32_t dw_length, uint16_t wCRC);

/**
 * @brief          CRC16 verify function
 * @param[in]      pch_message: data
 * @param[in]      dw_length:stream length = data + checksum
 * @retval         true of false
 */
/**
 * @brief          CRC16校验函数
 * @param[in]      pch_message: 数据
 * @param[in]      dw_length: 数据和校验的长度
 * @retval         真或者假
 */
uint32_t verify_CRC16_check_sum(uint8_t* pchMessage, uint32_t dwLength);

/**
 * @brief          append CRC16 to the end of data
 * @param[in]      pch_message: data
 * @param[in]      dw_length:stream length = data + checksum
 * @retval         none
 */
/**
 * @brief          添加CRC16到数据的结尾
 * @param[in]      pch_message: 数据
 * @param[in]      dw_length: 数据和校验的长度
 * @retval         none
 */
void append_CRC16_check_sum(uint8_t* pchMessage, uint32_t dwLength);

};  // namespace rp::crc
