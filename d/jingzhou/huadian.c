
// Room: /jingzhou/huadian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ȼ�е���ǰһ�����·��Ѿ���������������һ�����ֵĳ����
��������Եĸ����ʻ�������ŭ�ţ���չ���ᣬ���㲻��������һЩ�źá�
�����Ǹ�Ư����Ů���ӣ���������ʮ���ó������⣬ֻ�������վ��һ�ߣ�
�Ǻ����������������һ���˭˵����һ�����£�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nvrenjie3",
                "north"  : __DIR__"yingdulu",
        ]));
        set("objects", ([
                __DIR__"npc/flowersg" : 1,
                __DIR__"npc/huatong" : 1,                
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}