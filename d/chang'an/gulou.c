// Room: /chang'an/gulou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
������ǳ��ڵĵ���߽������¥�ˡ�����Ϊ��ש���ɣ��߰��ף���
����Լ��ʮ���ף��ϱ�����ʮ���ף��Ŷ��ߡ�������ף������ϴ�����롣
¥�彨��Ϊשǽľ������Ъɽʽ�������߸����������ˮ����һ��¥��
�����ܺ�ƽ����������¥ʮ�ּ�̣���������������ε���û���ѷ���
�Ρ���������ÿ������೵���¥���۹���Ҳδ��Ӱ�졣
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"nanyuanmen",
                "south" : __DIR__"nandajie1",
                "west"  : __DIR__"changjie",
                "north" : __DIR__"nandajie2",
                "up"    : __DIR__"gulouerceng",                             
        ]));
        setup();
}
