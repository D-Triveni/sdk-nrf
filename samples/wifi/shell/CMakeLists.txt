#
# Copyright (c) 2022 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nrf_wifi_shell)

set(WIFI_NRF_DRV_BASE ${WEST_TOPDIR}/nrf/drivers/wifi/nrf700x)
if(CONFIG_WPA_SUPP)
set(WPA_SUPP_BASE ${WEST_TOPDIR}/modules/lib/hostap)
endif()

# TODO: MbedTLS Remove this workaround
target_include_directories(mbedcrypto_common
	INTERFACE
	${CMAKE_SOURCE_DIR}
	inc
)

target_include_directories(app PUBLIC ${ZEPHYR_BASE}/subsys/net/ip)

# zephyr_library_compile_definitions(WFA_STA_TB)

target_sources(app PRIVATE
	src/wifi_main.c
	src/wfa_qt_shell.c
	src/qtrack/indigo_api_callback_dut.c
	src/qtrack/vendor_specific_dut.c
	src/qtrack/eloop.c
	src/qtrack/indigo_api.c
	src/qtrack/indigo_packet.c
	src/qtrack/qt_main.c
	src/qtrack/utils.c
	src/qtrack/wpa_ctrl.c
)
