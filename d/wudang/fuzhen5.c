// cangjingge.c �ؾ���
// by Xiang
// 05/30/96 Marz

inherit ROOM;

/*
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
*/
void create()
{
        set("short", "��������");
        set("long", @LONG
        �����Ǹ������㣬��ǽ��һ����ܣ������˵��̵ĵ伮����һЩ�书�ؼ���
�������䵱�صأ����䵱���Ӳ������ڡ�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"fuzhen4",
        ]));

        set("objects", ([
//              CLASS_D("wudang") + "/songqing" : 1,
//                "/u/fcxy/songqing":1,
        ]));

        set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",150);
	set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",150);
	set("coor/x",-60);
	set("coor/y",10);
	set("coor/z",150);
	setup();
        replace_program(ROOM);
}

