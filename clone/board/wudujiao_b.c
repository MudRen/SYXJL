// /clone/board/kedian_b.c
inherit BULLETIN_BOARD;
void create()
{
        set_name("�嶾�̵������԰�", ({ "board" }) );
        set("location", "/d/wudujiao/damen");
        set("board_id", "wudujiao_b");
        set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}




