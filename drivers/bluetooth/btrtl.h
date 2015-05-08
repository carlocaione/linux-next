/*
 *  Bluetooth support for Realtek devices
 *
 *  Copyright (C) 2015 Endless Mobile, Inc. 
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#define RTL_FRAG_LEN 252

struct rtl_download_cmd {
	__u8 index;
	__u8 data[RTL_FRAG_LEN];
} __packed;

struct rtl_download_response {
	__u8 status;
	__u8 index;
} __packed;

struct rtl_rom_version_evt {
	__u8 status;
	__u8 version;
} __packed;

struct rtl_epatch_header {
	__u8 signature[8];
	__le32 fw_version;
	__le16 num_patches;
} __packed;

#define RTL_EPATCH_SIGNATURE	"Realtech"
#define RTL_ROM_LMP_3499	0x3499
#define RTL_ROM_LMP_8723A	0x1200
#define RTL_ROM_LMP_8723B	0x8723
#define RTL_ROM_LMP_8821A	0x8821
#define RTL_ROM_LMP_8761A	0x8761


#if IS_ENABLED(CONFIG_BT_RTL)

int btusb_setup_realtek(struct hci_dev *hdev);

#else

static inline int btusb_setup_realtek(struct hci_dev *hdev)
{
	return -EOPNOTSUPP;
}

#endif
