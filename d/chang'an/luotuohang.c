
// Room: /chang'an/luotuohang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ڳ�����˿��֮·����㣬�������������˻���ȫҪ����Щ�����ˣ�
˭��˵���������ֶ����ܴ�Խ��ɳĮ�Ļ�������һ���Ǹ����ӡ��������
�����úܻ����ȥ��˹�Ļ���������ϰ����ܺ��ʵ��̶Ӱ����ӹ�ȥ��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beidajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}