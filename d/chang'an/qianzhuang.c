
// Room: /chang'an/qianzhuang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ǯׯ");
        set("long", @LONG
�����ǳ�����Ǯׯ����Ϊ������ҵ�ǳ�������ص��̺Ŷ���������
��Ǯ������Ǯׯ���кܶ����ڴ�ȡǮ��Ҳ�����ڶһ�������������ô���
Ǯ�ƹ�����ȥ�����������۲�����
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"beidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}