inherit BULLETIN_BOARD;

void create()
{
        set_name("���ư�", ({ "board" }) );
        set("location", "/u/linghu/gate");
        set("board_id", "biwu_b");
        set("long", "����һ������ר�ñ������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

