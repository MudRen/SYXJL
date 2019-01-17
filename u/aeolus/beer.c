// beer.c

inherit ITEM;

inherit F_LIQUID;


void create()

{

	set_name("ÇàµºÆ¡¾Æ", ({"tsingtao beer", "beer"}));

	set_weight(700);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("long", "Ò»Æ¿ÓÃáÀÉ½¿óÈªÄğÖÆµÄ¸ÊÌğµÄÆ¡¾Æ¡£\n");

		set("unit", "Æ¿");

		set("value", 200);

		set("max_liquid", 30);

	}


	set("liquid", ([

		"type": "alcohol",

		"name": "Æ¡¾Æ",

		"remaining": 30,

		"drunk_apply": 20,

	]) );

}
