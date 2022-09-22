#
# Copyright (c) 2022 Nordic Semiconductor ASA
#
# SPDX-License-Identifier: LicenseRef-Nordic-5-Clause
#

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(nrf_wifi_sta)

if(CONFIG_WPA_SUPP)
set(WPA_SUPP_BASE ${WEST_TOPDIR}/modules/lib/hostap)
endif()

# TODO: MbedTLS Remove this workaround
target_include_directories(mbedcrypto_common
    INTERFACE
    ${CMAKE_SOURCE_DIR}
)

target_include_directories(app PUBLIC ${ZEPHYR_BASE}/subsys/net/ip)

target_compile_definitions_ifdef(CONFIG_WPA_SUPP_CRYPTO
	app
	PRIVATE
	CONFIG_WEP
)

target_sources(app PRIVATE
	src/main.c
)
