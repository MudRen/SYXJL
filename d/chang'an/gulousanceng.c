inherit ROOM;
int flag=0;
void create()
{
        set("short", "��¥����");
        set("long", @LONG
����վ�ڹ�¥��¥�����������ʮ�ĸ���ɫ��������ʮ�ĸ���������
�������ڹ���ֻ�󹬵ơ�ʮ��ֻ�й��ơ�ʮ��ֻС���ơ��컨���������
������ͼ�����ϡ�����¥������������(bian)����Ϊ������ʢ�ء�������
Ǭ¡�ʵ����ʿ��顣��Ϊ���������족�����������ʿ���д��ÿ����Լ��
�֣��ּ��վ�����������ػ���ƾ��������ȫ�Ǿ�ɫ�����۵ס�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "down"  : __DIR__"gulouerceng",                       
        ]));
        set("item_desc", ([
            "guan cai" : "һ��������ֵĴ��ҡ�\n",
            
        ]));


        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_dakai", "tiao");                 
}
int do_dakai(string arg)
{
        object me=this_player();
        object ob;
        if(!arg || arg!="bian")
                return notify_fail("������ʲô����\n");
        
        else if ( flag==0 )
                {
                        flag=1;
                        message_vision("����������������ҿ�����ϸЩ....�ۣ������Ȼ��һ�����.\n",me);
                        message_vision("$N���¿��˿�����æ�ѹ��񴧽��˶���.\n",me);
                ob = new ( __DIR__"obj/wenyu" );
                ob->move( this_player() );

                }
             else message_vision("�ҵĺ���տյģ�ʲô��û�С�\n",me);            

        return 1;
}

