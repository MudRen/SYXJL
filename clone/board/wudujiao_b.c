// /clone/board/kedian_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("五毒教弟子留言板", ({ "board" }) );
        set("location", "/d/wudujiao/damen");
        set("board_id", "wudujiao_b");
        set("long", "有有用的话就往这里说，乱灌水杀无赦。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}




