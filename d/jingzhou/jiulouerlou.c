
// Room: /jingzhou/jiulouerlou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��¥��¥");
        set("long", @LONG
�����������������ͷ���Ҫ�õö࣬��Ȼ�۸����ҲҪ��һЩ������
���������Ķ���Щ�����˼ң�����߳Ժȱ������ס�����ż����Щ����ѧʿ
Ҳ������������ʫ����������Ҳ�ǳ���ٰ�ϲ�����ѳ�����������һ�غ�
ˮ���̲�������������˳�ǽ����һ��������ͷ����Ұ��ǽ�Ϲ��ż۸����ӡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "down"  : __DIR__"jiulou",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}