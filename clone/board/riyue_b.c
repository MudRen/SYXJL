// /clone/board/riyue_b.c



inherit BULLETIN_BOARD;



void create()

{

	set_name("������̵������԰�", ({ "board" }) );

        set("location", "/d/heimuya/pailou");
        set("board_id", "riyue_b");;

	set("long", "����һ����������̵��ӽ��������԰塣\n" );

	setup();

	set("capacity", 30);

	replace_program(BULLETIN_BOARD);

}



