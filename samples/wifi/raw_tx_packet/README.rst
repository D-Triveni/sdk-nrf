.. _wifi_raw_tx_packet_sample:

Wi-Fi: Raw TX Packet
####################

.. contents::
   :local:
   :depth: 2

The Raw TX Packet sample demonstrates how to transmit raw TX packets.

Requirements
************

The sample supports the following development kits:

.. table-from-sample-yaml::

Overview
********
The sample demonstrates how to transmit raw TX packets in both station-connected and station-idle modes of operation.
The sample provides the option to transmit raw TX packets either continuously or a fixed number of packets.

Configuration
*************

|config|

Configuration options
=====================

The following sample-specific Kconfig options are used in this sample (located in :file:`samples/wifi/raw_tx_packet/Kconfig`) :

.. options-from-kconfig::

**Configuration options for connected mode:**

To configure the sample in connected mode, you must configure the following Wi-Fi credentials in the :file:`prj.conf` file:

* ``Service Set Identifier (SSID)``: Define the name of your Wi-Fi network.
* ``Key management``: Specify the key management method, such as WPA2, WPA3, or other encryption protocols.
* ``Password``: Set the pre-shared key of your Wi-Fi network.

.. note::
   You can also use ``menuconfig`` to enable ``Key management`` option.

See :ref:`zephyr:menuconfig` in the Zephyr documentation for instructions on how to run ``menuconfig``.

**Configuration options for IDLE mode:**

To configure the sample in idle mode, you must configure the following parameter in the :file:`prj.conf` file:

* ``Channel``: Specify the Wi-Fi channel to be used for communication on the wireless network.

**Configuration options for Raw TX Packet header:**

* ``Rate value``: Specify the data transmission rate.
* ``Rate flags``: Specify the data transmission mode.
* ``Queue number``: Specify the transmission queue to which raw TX packets are assigned for sending.

Additionally, you must configure the following option in the :file:`prj.conf` file: to define the time delay between raw TX packets.

* ``Inter frame delay``: Set the time duration between raw Tx packets.

IP addressing
*************
The sample uses DHCP to obtain an IP address for the Wi-Fi interface.
It starts with a default static IP address to handle networks without DHCP servers, or if the DHCP server is not available.
Successful DHCP handshake will override the default static IP configuration.

You can change the following default static configuration in the :file:`prj.conf` file:

.. code-block:: console

  CONFIG_NET_CONFIG_MY_IPV4_ADDR="192.168.1.98"
  CONFIG_NET_CONFIG_MY_IPV4_NETMASK="255.255.255.0"
  CONFIG_NET_CONFIG_MY_IPV4_GW="192.168.1.1"

Building and running
********************

.. |sample path| replace:: :file:`samples/wifi/raw_tx_packet`

.. include:: /includes/build_and_run_ns.txt

The sample can be built for the following configurations:

* Continuous transmission with the station-connected mode.
* Fixed number of packet transmission with the station-connected mode.
* Continuous transmission with the station-idle mode.
* Fixed number of packet transmission with the station-idle mode.

To build for the nRF7002 DK, use the ``nrf7002dk_nrf5340_cpuapp`` build target.
The following are examples of the CLI commands:

* Continuous transmission with the station-connected mode:

  .. code-block:: console

     west build -b nrf7002dk_nrf5340_cpuapp -- -DCONFIG_RAW_TX_PACKET_SAMPLE_CONNECTION_MODE=y -DCONFIG_RAW_TX_PACKET_SAMPLE_PACKET_TRANSMISSION_MODE=0

* Fixed number of packet transmission with the station-connected mode:

  .. code-block:: console

     west build -b nrf7002dk_nrf5340_cpuapp -- -DCONFIG_RAW_TX_PACKET_SAMPLE_CONNECTION_MODE=y -DCONFIG_RAW_TX_PACKET_SAMPLE_PACKET_TRANSMISSION_MODE=1 -DCONFIG_RAW_TX_PACKET_SAMPLE_FIXED_NUM_PACKETS=<number of packets to be sent>

* Continuous transmission with the station-idle mode:

  .. code-block:: console

     west build -b nrf7002dk_nrf5340_cpuapp -- -DCONFIG_RAW_TX_PACKET_SAMPLE_IDLE_MODE=y -DCONFIG_RAW_TX_PACKET_SAMPLE_PACKET_TRANSMISSION_MODE=0

* Fixed number of packet transmission with the station-idle mode:

  .. code-block:: console

     west build -b nrf7002dk_nrf5340_cpuapp -- -DCONFIG_RAW_TX_PACKET_SAMPLE_IDLE_MODE=y -DCONFIG_RAW_TX_PACKET_SAMPLE_PACKET_TRANSMISSION_MODE=1 -DCONFIG_RAW_TX_PACKET_SAMPLE_FIXED_NUM_PACKETS=<number of packets to be sent>

Change the build target as given below for the nRF7002 EK.

.. code-block:: console

   nrf5340dk_nrf5340_cpuapp -- -DSHIELD=nrf7002ek

Testing
=======

|test_sample|

#. |connect_kit|
#. |connect_terminal|

   The sample shows the following output:

   .. code-block:: console

      [00:00:00.469,940] <err> wifi_nrf: Firmware (v1.2.8.99) booted successfully

      *** Booting nRF Connect SDK 9a9ffb5ebb5b ***
      [00:00:00.618,713] <inf> net_config: Initializing network
      [00:00:00.618,713] <inf> net_config: Waiting interface 1 (0x20001570) to be up...
      [00:00:00.618,835] <inf> net_config: IPv4 address: 192.168.1.99
      [00:00:00.618,896] <inf> net_config: Running dhcpv4 client...
      [00:00:00.619,140] <inf> raw_tx_packet: Starting nrf7002dk_nrf5340_cpuapp with CPU frequency: 64 MHz
      [00:00:01.619,293] <inf> raw_tx_packet: Static IP address (overridable): 192.168.1.99/255.255.255.0 -> 192.168.1.1
      [00:00:01.632,507] <inf> raw_tx_packet: Wi-Fi channel set to 6
      [00:00:01.632,598] <inf> raw_tx_packet: Sending 25 number of raw tx packets
      [00:00:01.730,010] <inf> net_config: IPv6 address: fe80::f6ce:36ff:fe00:2282

Dependencies
************

This sample uses the following library:

* :ref:`nrf_security`
