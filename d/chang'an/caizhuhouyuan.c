
// Room: /chang'an/caizhuhouyuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������Ժ");
        set("long", @LONG
�����ǲ�����Ժ�����ֹ���������Ŀ��������ͭ�������ʡ�����Ӧ��
���У�ֻҪӵ��һ�����͹����һ�����ˡ���Ա������������ϣ�������
�غ������
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"caizhudayuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}