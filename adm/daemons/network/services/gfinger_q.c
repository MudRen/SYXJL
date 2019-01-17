/*
 * File    : gfinger_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is a request for information about a user at another mud.
 */
 

// Ported to ES2 mudlib by Annihilator@ES2 (06/15/95)
// modify by ken@XAJH (97-11-18)

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;

void create() {
	seteuid(ROOT_UID);
	set("channel_id", "��·Ƶ������");
}

// Finger a wiz on another mud.
void send_gfinger_q(string mud, string wiz, object them)
{
	mapping minfo;

	if(!ACCESS_CHECK(previous_object())) return;

	if (!them) them = this_player(1);
	mud = htonn( mud );

	if (mud == mud_nname()) return ;
	// make sure we have an entry for the recipient
	minfo = DNS_MASTER->query_mud_info(mud);
	if (!minfo) return ;

	// send the finger
	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		sprintf("@@@%s||NAME:%s||PORTUDP:%d||PLAYER:%s||ASKWIZ:%s@@@\n",
		DNS_GFINGER_Q, Mud_name(), udp_port(),
		wiz, (string)them->query("id")));
}

void incoming_request(mapping info)
{
	mapping minfo;
	string reply;
	int code;

	if (info["NAME"] && info["PORTUDP"] && info["PLAYER"]) {
		if (info["NAME"] == mud_nname()) return ;

		// get our info about the sender, ping them if we don't have any
		minfo = DNS_MASTER->query_mud_info(info["NAME"]);
		// if we don't have a record of the mud get it
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

		// add checking encoding isBig5 or not by ken@XAH at 1998-06-08
		code = LOCATE_A->encoding(minfo["HOSTADDRESS"]);
		if( minfo["ENCODING"] == "GB" )	code = 0;

		// send the finger reply
                reply = FINGER_D->remote_finger_user(lower_case(info["PLAYER"]),1);
		if( code == 1)
			reply = LANGUAGE_D->toBig5(reply);

		DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
			sprintf("@@@%s||NAME:%s||PORTUDP:%d||ASKWIZ:%s||MSG:%s@@@\n",
			DNS_GFINGER_A, mud_nname(), udp_port(),
			info["ASKWIZ"], reply));
	}
}

