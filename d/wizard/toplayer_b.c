// /clone/board/toplayer_b.c

inherit WIZ_BULLETIN_BOARD;

void create()
{
        set_name("玩家意见处理板", ({ "board" }) );
        set("location", "/d/wizard/chuli");
        set("board_id", "toplayer_b");
        set("long", "这是一个巫师处理玩家意见的留言板。\n" );
        set("wiz_only", 1);
        setup();
        set("capacity", 100);
        replace_program(WIZ_BULLETIN_BOARD);
}

