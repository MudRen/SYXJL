// Room: /d/wuguan/dayuan.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "��ݴ�Ժ");
        set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ������
�ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�����
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("exits", ([
                "south" : __DIR__"",
        ]));
        setup();
        replace_program(ROOM);
}
