// /clone/board/toplayer_b.c

inherit WIZ_BULLETIN_BOARD;

void create()
{
        set_name("�����������", ({ "board" }) );
        set("location", "/d/wizard/chuli");
        set("board_id", "toplayer_b");
        set("long", "����һ����ʦ���������������԰塣\n" );
        set("wiz_only", 1);
        setup();
        set("capacity", 100);
        replace_program(WIZ_BULLETIN_BOARD);
}

