
// Room: /chang'an/guwandian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
������ϰ�մ�����������һ���ĺ���֮����������ҥ��˵�����ǵ�
����д�ɳĮ�ġ������硱��������Щҥ�ԣ����ϰ�Ҳ���޿��κΡ���˵��
�����е��������þã�һֱû��ʲô֤�ݣ�Ҳ�Ͱ��ˡ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"yaowangdong",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}