
// Room: /chang'an/dangpu.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���Ǽ�Զ�������ĵ��̣�����������棬һ��д�š����ǵ��̡��ĸ�
���ֵĺ��ң������߳߸ߵ���̴ľ�Ĺ�̨��ĥ�ù�����ˣ���һ��ȥ����
һ��ѹ�ֺͱ���ĸо�����̨������ϰ�Ҳ��̧��ֻ�˲��������̣���̨
�Ϸ�����һ�黨ľ���ӣ�paizi�� ���ݽַ���˵���̸��ļۻ��������
���Ҵ������ʻ������������˻���ʲô���գ���������ܲ���
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"beidajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}