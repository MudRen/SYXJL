 // room: /kunlun/lianwu2.c

inherit ROOM;



void create()

{

        set("short", "���䳡");

        set("long", @LONG

�����ǹ����ϵ͵����ص��Ӳ�������ȭ�ŵĵط��������г�����ɳ����ľ

׮�����������ĵ����������ڵ��������������Խ�������, ��Ҳʮ������

ȭ���Ļ������򣬹ʴ����ŵ��Ӷ��ڴ˴�����, �ȴ���һ�����׺��ܵ���

�ϳ��书��

LONG

        );

        set("exits", ([

                "west" : __DIR__"qianting",

        ]));

        set("objects", ([ /* sizeof() == 1 */

                "/d/kunlun/npc/muren" :   2,

         ]));        setup();

        replace_program(ROOM);

}





