// /clone/board/honghua_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("�컨��������԰�",({"board"}));
	set("location","/d/honghua/zongduo");
	set("board_id", "hongh_b");
	set("long", "���ǹ��컨��������Եİ���.\n");
	setup();
	set("capacity", 30);
	replace_program(BULLETIN_BOARD);
}

