#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIC "������������ָ�ϡ�" NOR, ({ "rumen zhinan", "zhinan" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long",@LONG         
����������

�书:
    blade  yanxing-dao
    sword fuliu-jian
    finger tiangang-zhi
    strike jinding-mianzhang
    force linji-zhuang
    throwing pili-dan
    dodge zhutian
  perform 
    blade (������)
    strike (������)
    sword �� perform sword.miejian
              �����˵Ĺ���
    throwing �� perform throwing.tan sb.
              �����������ˣ���������һ��
  
��ʦ:
    ��ɽ��������ʦ̫�շǱ���֮ͽ,ֱ�Ӱ�ʦ����.
��ͽ��������ҵ��������ֱ�����(����),�׼�����.
��������: 
         ask miejue about ������
         give ling to (ʦ������ͽ��npc)
         fight npc (�õ�������)
         give jieshao-xin1 to (ʦ�汲��ͽ��npc)
         bai this npc
��ɽ����:
         ask miejue about ��ɽ
         ���߿߷�������������,ɱ֮,�����߿߾�ͷ�Ϳɻ�ȥ������.
         ask miejue about ��ɽ    
         PS:�߿���ÿ���˽����clone����������.
����ָ��:
         �ڻ﷿����(work),һ�κ�50��,ͣ5��,��һ������
         ���ŷ�����(yao),һ�κ�30��,ͣ5��,�õ���Ҫ�Եĺͺȵ�.
         ����Ƹ����(fill sth),��ˮ.
         �ں���ʦ̨�ǿ���(ling mudao,ling zhujian).
             PS:zhujian and mudao no value,���ӵ��ϻ���.
         �ں�ɽ����(search)����ҩ,�˲�ʲô��,��ҩ�õ�
             ҩ��������Խ�������ʦ̫��ҩ�õ���ҩ. 
         PS:��ʱ���ѳ�һ�����ߡ�
         caoyao�ָ�����5��zhongyao�ָ�����10��
         renshen����������5����ÿ�α������search������
         ������ɽ����(search)����ǣ���������ʦ̫��������������
         ��ǧ���ִ�����С��������һЩ�ճ���Ʒ.
         ��ɽ�ŵ���С�������������õĶ���.
         �Ͻ𶥿����þ����ķ�������Լ���Ǳ��.
             PS:�Ͻ�Ҫ���ƺ�,����һ������Թ�,ÿ��·����һ��.
����:
         ����������perform,
         ���ɵ���(δ��ʦ)���м��ʼ�����(������)
LONG );


		set("value", 50);
		set("material", "paper");
	}
	setup();
}
