.. _wifi_station_sample:

Wi-Fi: Station
##############

.. contents::
   :local:
   :depth: 2

This sample demonstrates how to connect the Wi-Fi Station to a specified Access Point.

Requirements
************

The sample supports the following development kit:

.. table-from-sample-yaml::

Overview
********

This sample can perform Wi-Fi operations "Connect and Disconnect" in the 2.4GHz and 5GHz bands depending on the capabilities of an Access point.

Using this sample, the development kit can connect to the specified Access Point :abbr:`STA (Station)` mode.

Building and running
********************

.. |sample path| replace:: :file:`samples/wifi/sta`

.. include:: /includes/build_and_run_ns.txt

Currently, the following board(s) are supported:

* nRF7002 DK

The below parameters should be configured in ``prj.conf``:

* Network Name (SSID)
* Key Management
* Password

To build for the nRF7002 DK, use the ``nrf7002dk_nrf5340_cpuapp`` build target.
The following is an example of the CLI command::

   west build -b nrf7002dk_nrf5340_cpuapp

Testing
=======

|test_sample|

#. |connect_kit|
#. |connect_terminal|

   The output should be similar to the following::

      <inf> sta: Connection requested
      <inf> sta: Connected
      Status: successful
      ==================
        State: COMPLETED
        Interface Mode: STATION
        Link Mode: WIFI 6 (802.11ax/HE)
        SSID: NORDIC-GUEST
        BSSID: F0:1D:2D:72:EB:EF
        Band: 5GHz
        Channel: 116
        Security: WPA2-PSK
        MFP: Optional
        RSSI: -55
      <inf> sta: IP address: 192.168.48.41
      <inf> sta: Disconnect requested
      <inf> sta: Disconnection request done (0)
      Status: successful
      ==================
        State: DISCONNECTED

Dependencies
============

This sample uses the following `sdk-nrfxlib`_ library:

* :ref:`nrfxlib:nrf_security`

This sample also uses modules that can be found in the following locations in the |NCS| folder structure:

* ``modules/lib/hostap``
* ``modules/mbedtls``
