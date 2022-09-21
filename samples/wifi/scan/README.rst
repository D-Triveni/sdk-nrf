.. _wifi_scan_sample:

Wi-Fi: Scan
############

.. contents::
   :local:
   :depth: 2

This sample allows the Nordic Wi-Fi chipset to scan for the Access points.

Requirements
************

The sample supports the following development kit:

.. table-from-sample-yaml::

Overview
********

This sample can perform Wi-Fi operation "Scan".

Using this sample, the development kit can scan for access points in :abbr:`STA (Station)` mode.

Building and running
********************

.. |sample path| replace:: :file:`samples/wifi/scan`

.. include:: /includes/build_and_run_ns.txt

Currently, the following configurations are supported:

* 7002 DK + QSPI
* 7002 EK + SPIM


To build for the nRF7002 DK, use the ``nrf7002dk_nrf5340_cpuapp`` build target.
The following is an example of the CLI command::

   west build -b nrf7002dk_nrf5340_cpuapp

To build for the nRF7002 EK, use the ``nrf7002dk_nrf5340_cpuapp`` build target with the ``SHIELD`` CMake option set to ``nrf7002_ek``.
The following is an example of the CLI command::

   west build -b nrf5340dk_nrf5340_cpuapp -- -DSHIELD=nrf7002_ek

See also :ref:`cmake_options` for instructions on how to provide CMake options.

Testing
=======

|test_sample|

#. |connect_kit|
#. |connect_terminal|
   The output should be similar to the following::

      Scan requested
      Num  | SSID                             (len) | Chan | RSSI | Sec
      1    | dlink-7D64                       10    | 1    | 0    | WPA/WPA2
      2    | abcd_527_24                      11    | 4    | 0    | Open
      3    | ASUS_RTAX88U11g                  15    | 3    | 0    | WPA/WPA2
      4    | TP-Link_6BA8                     12    | 9    | 0    | WPA/WPA2
      Scan request done

Dependencies
============

This sample uses the following `sdk-nrfxlib`_ library:

* :ref:`nrfxlib:nrf_security`

This sample also uses modules that can be found in the following locations in the |NCS| folder structure:

* ``modules/lib/hostap``
* ``modules/mbedtls``
