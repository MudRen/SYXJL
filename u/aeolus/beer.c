// beer.c

inherit ITEM;

inherit F_LIQUID;


void create()

{

	set_name("�ൺơ��", ({"tsingtao beer", "beer"}));

	set_weight(700);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("long", "һƿ����ɽ��Ȫ���Ƶĸ����ơ�ơ�\n");

		set("unit", "ƿ");

		set("value", 200);

		set("max_liquid", 30);

	}


	set("liquid", ([

		"type": "alcohol",

		"name": "ơ��",

		"remaining": 30,

		"drunk_apply": 20,

	]) );

}
