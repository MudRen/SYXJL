// xxh5.c

// by QingP



inherit ROOM;



void create()

{

        set("short", "���޺�");

        set("long", @LONG

���������޺��ľ�ͷ����Ϊ������Ұ���û�����������ɵ��ӳ����ڴ˿����⴮

�ԡ����򲻵�Ұ��ʱ�����Ǿ���ɽ�����˵���

LONG

        );

        set("exits", ([

             "southeast" : __DIR__"xxh3",

             "southwest" : __DIR__"xxh4",

        ]));

        set("objects", ([

                __DIR__"npc/boshou"  : 1,

                __DIR__"obj/yangrouchuan.c" : 2]));



        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");



        setup();

        replace_program(ROOM);



}



