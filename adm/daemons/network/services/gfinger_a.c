/*
 * File    : gfinger_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol contains the answer to a gfinger request.
 */

// Ported to ES2 mudlib by Annihilator@ES2 (06/15/95)

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

// They answered our finger request.  Nice of them.
void incoming_request(mapping info)
{
	mapping minfo;
	object ob;
	int code;

	if(!ACCESS_CHECK(previous_object())) return;

	if (info["PORTUDP"] && info["NAME"]) {
		// dont want to finger ourselves
		if (info["NAME"] == Mud_name()) return ;

		// get our info about the sender, ping them if we don't have any
		minfo = DNS_MASTER->query_mud_info(info["NAME"]);

		// if we haven't got an entry for the mud, get one.
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

		// send the info to the player
		ob = find_player(lower_case(info["ASKWIZ"]));
//		if (ob)	message("finger", sprintf("Finger from %s��\n",info["NAME"]),ob);


		// add checking encoding isBig5 or not by ken@XAH at 1998-06-08
		code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
		if( minfo["ENCODING"] == "GB" )	code = 0;
		if( code == 1)
			message("finger", LANGUAGE_D->toGB(info["MSG"]),ob);
		else
			message("finger", info["MSG"],ob);
	}
}
