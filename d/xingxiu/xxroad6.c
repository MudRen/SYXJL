// xxroad6.c
// by QingP

inherit ROOM;

void create()
{
        set("short", "ɽ��ƽ��");
        set("long", @LONG
    ɽ��ƽ�أ����������̵�С�ݣ���Χ���˼���������ɽ����һ����Ȫ(qingquan)��
LONG
        );

        set("resource/water", 1);
        
        set("objects", ([
                __DIR__"obj/yangrouchuan.c" : 3]));


        set("exits", ([
  "south" : __DIR__"xxroad5",
]));

        set("item_desc", ([
                "qingquan" : "Ȫˮ����������...�㿴���峺���׵�Ȫˮ�������Լ��ƺ��е���ˡ�\n"

        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	set("coor/x",-130);
	set("coor/y",80);
	set("coor/z",20);
	setup();
        replace_program(ROOM);
}
