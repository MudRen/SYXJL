// Room: /chang'an/nvlao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů��");
        set("long", @LONG
�ں����ļ���ʲô�����������ͷ��ż�������������ڳ���������
���Ӷ��Ҫ������������������Ҳ���ֺ�ҹ�Ͱ��죬ÿ����ֻ�а���ֺ�
��Ӳ����ͷ��һ��������������ˮ����װ����ˮ�����Ҫ�����������
����ܶ࣬�������������һ��ʱ�䣬�����������Ѿ����������ǵ��Ա�
�ˡ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"jianyuguodao",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}