// /clone/board/kedian_b.c



inherit BULLETIN_BOARD;



void create()

{

        set_name("���԰�", ({ "board" }) );
        set("location", "/d/chang'an/zhonglouerceng");
        set("board_id", "ca_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );

	setup();

          set("capacity", 1000);
	replace_program(BULLETIN_BOARD);

}



