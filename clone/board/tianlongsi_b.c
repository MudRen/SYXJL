// /clone/board/shaolin_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("�����µ������԰�", ({ "board" }) );
        set("location", "/d/tls/baodian");
        set("board_id", "tianlongsi_b");
        set("long", "����һ���������µ��ӽ��������԰塣\n" );
	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}

