// /clone/board/huashan_b.c



inherit BULLETIN_BOARD;



void create()

{

	set_name("��ɽ�ɵ������԰�", ({ "board" }) );

	set("location", "/d/huashan/buwei1");

	set("board_id", "huashan_b");

	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );

	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}



