inherit ROOM;

void create()
{
	set("short", "�鷿");
	set("long", @LONG
    ����һ��ɸɾ������鷿������һ����̴ľ�������Ϸ��Ų����鼮��
��ǽ�ĵط�����һ����ܣ�����������ȫ�Ǹ��ַ�װ���顣���в����鿴��ȥ
���ⰻȻ����Ȼ����Ѿá�
LONG
	);
    set("exits", ([
    "west" : __DIR__"dating",
]));
     set("objects", ([
        __DIR__"npc/yapu" : 2,
             __DIR__"obj/xiang" : 2,
           "/kungfu/class/taohua/qulingf":1,
    ]) );    

	set("coor/x",60);
	set("coor/y",-230);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
