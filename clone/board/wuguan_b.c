// /clone/board/kedian_b.c



inherit BULLETIN_BOARD;



void create()

{

          set_name("������԰�", ({ "board" }) );
          set("location", "/d/wuguan/wuguandayuan");
         set("board_id", "wuguan_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );

	setup();

          set("capacity", 1000);
	replace_program(BULLETIN_BOARD);

}



