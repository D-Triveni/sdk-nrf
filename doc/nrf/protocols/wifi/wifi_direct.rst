.. _ug_wifi_direct:

Wi-Fi Direct (P2P mode)
#######################

.. contents::
   :local:
   :depth: 2

Wi-Fi Direct® (also known as Wi-Fi P2P or peer-to-peer mode) enables direct device-to-device connections without requiring a traditional access point.
The nRF70 Series devices support Wi-Fi Direct, allowing you to establish peer-to-peer connections with other Wi-Fi Direct-capable devices.

Building with Wi-Fi Direct support
***********************************

To build an application with Wi-Fi Direct support, use the Wi-Fi shell sample with the ``wifi-p2p`` snippet and external flash for firmware patches.

Build command
=============

Use the following command to build the Wi-Fi shell sample with P2P support:

.. code-block:: console

   west build --pristine --board nrf7002dk/nrf5340/cpuapp -S wifi-p2p -S nrf70-fw-patch-ext-flash
   west flash

Wi-Fi Direct commands
**********************

The following commands are available for Wi-Fi Direct operations.
Both Wi-Fi shell commands and wpa_cli commands are shown for each operation:

Finding peers
=============

To start discovering Wi-Fi Direct peers:

**Wi-Fi shell command:**

.. code-block:: console

   wifi p2p find

**wpa_cli command:**

.. code-block:: console

   wpa_cli p2p_find

This command initiates the P2P discovery process. The device will scan for other Wi-Fi Direct-capable devices in range.

Listing discovered peers
=========================

To view the list of discovered peers:

**Wi-Fi shell command:**

.. code-block:: console

   wifi p2p peer

**wpa_cli command:**

.. code-block:: console

   wpa_cli p2p_peers

This displays a table of discovered peers with the following information:

.. code-block:: console

   Num  | Device Name                      | MAC Address       | RSSI | Device Type          | Config Methods
   1    | Galaxy S22                       | D2:39:FA:43:23:C1 | -58  | 10-0050F204-5        | 0x188

Where:

* **Num** - Sequential number of the peer in the list
* **Device Name** - Friendly name of the peer device
* **MAC Address** - MAC address of the peer device
* **RSSI** - Signal strength in dBm
* **Device Type** - WPS device type identifier
* **Config Methods** - Supported WPS configuration methods

Getting peer details
====================

To get detailed information about a specific peer:

**Wi-Fi shell command:**

.. code-block:: console

   wifi p2p peer <mac_address>

**wpa_cli command:**

.. code-block:: console

   wpa_cli p2p_peer <mac_address>

For example:

.. code-block:: console

   wpa_cli p2p_peer D2:39:FA:43:23:C1

This displays detailed information about the specified peer device.

Connecting to a peer
====================

To establish a Wi-Fi Direct connection with a discovered peer:

**Wi-Fi shell command:**

.. code-block:: console

   wifi p2p connect <mac_address> [pin|pbc] -g <go_intent>

**wpa_cli command:**

.. code-block:: console

   wpa_cli p2p_connect <mac_address> <pbc|pin> [go_intent=<0..15>]

Parameters:

* **mac_address** - MAC address of the peer device to connect to
* **pin|pbc** - WPS provisioning method:

  * ``pin`` - Use PIN-based WPS authentication. The command will return a PIN (for example, ``88282282``) that must be entered on the peer device.
  * ``pbc`` - Use Push Button Configuration (PBC) for WPS authentication.

* **go_intent** - Group Owner (GO) intent value (0-15):

  * Higher values indicate a stronger desire to become the Group Owner
  * Value of 15 forces the device to become the GO
  * Value of 0 indicates the device prefers to be a client

Example connection with PIN method:

**Wi-Fi shell command:**

.. code-block:: console

   wifi p2p connect D2:39:FA:43:23:C1 pin -g 0

**wpa_cli command:**

.. code-block:: console

   wpa_cli p2p_connect D2:39:FA:43:23:C1 pin go_intent=0

The command will output a PIN (for example, ``88282282``) that should be entered on the peer device to complete the connection.

To disconnect from a Wi-Fi Direct connection:

**Wi-Fi shell command:**

.. code-block:: console

   wifi disconnect

**wpa_cli command:**

.. code-block:: console

   wpa_cli disconnect
