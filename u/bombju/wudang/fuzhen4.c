// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz

inherit ROOM;

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "������Ĳ�");
	set("long", @LONG
	�����Ǹ���۶��㣬���䵱�ղص��̵伮�ĵط�����ǽ��һ����ܣ������˵��̵ĵ伮��������һ������
�εĴ����ӣ�����Ҳ�������顣һ����ͯ���������鼮��
LONG
	);

	set("exits", ([
		"eastdown" : __DIR__"fuzhen3",
		"northup" : __DIR__"fuzhen5",
	]));

	set("objects", ([
		CLASS_D("wudang") + "/daotong" : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1,
		__DIR__"obj/"+books[random(sizeof(books))] : 1
	]));

	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",140);
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",140);
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",140);
	setup();
	replace_program(ROOM);
}