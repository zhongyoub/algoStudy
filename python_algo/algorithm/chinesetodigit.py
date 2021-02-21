#!/usr/bin/python3
#coding:utf-8

'''
给定一个表示金额的大写汉字，转换成阿拉伯数字表示的金额
输入：金额的中文大写
输出：阿拉伯数字
(1)用正则表达式按照模板检索
'''
import re

def convert_cndigit(xxx):
    CN_NUM1 = {
        '〇' : 0, '一' : 1, '二' : 2, '三' : 3, '四' : 4, '五' : 5, '六' : 6, '七' : 7, '八' : 8, '九' : 9, '零' : 0,
        '壹' : 1, '贰' : 2, '叁' : 3, '肆' : 4, '伍' : 5, '陆' : 6, '柒' : 7, '捌' : 8, '玖' : 9, '貮' : 2, '两' : 2,
    }
    CN_NUM = {
        '零' : 0,
        '壹' : 1,
        '贰' : 2, 
        '叁' : 3,
        '肆' : 4, 
        '伍' : 5, 
        '陆' : 6, 
        '柒' : 7, 
        '捌' : 8, 
        '玖' : 9
    }
    CN_UNIT1 = {
        '十' : 10,
        '拾' : 10,
        '百' : 100,
        '佰' : 100,
        '千' : 1000,
        '仟' : 1000,
        '万' : 10000,
        '萬' : 10000,
        '亿' : 100000000,
        '億' : 100000000,
        '兆' : 1000000000000,
    }
    CN_UNIT = {
        '拾' : 10,
        '佰' : 100,
        '仟' : 1000,
        '萬' : 10000,
        '亿' : 100000000,
        '兆' : 1000000000000,
    }

    #regex = re.compile(r'[〇一二三四五六七八九零壹贰叁肆伍陆柒捌玖貮两十拾百佰千仟万萬亿億兆元角分]+')
    regex = re.compile(r'[零壹贰叁肆伍陆柒捌玖拾佰仟萬亿兆元角分]+')
    xxx = regex.search(xxx)
    if xxx:
        xxx = xxx.group()
    else:
        return None
    result = 0
    result_list = []
    unit = 0
    control = 0
    for i, d in enumerate(xxx):
        if d in '零百佰千仟万萬亿億兆〇' and i == 0:
            return '大写数字格式有误'
            break
        if d == '元':
            continue
        if d == '角':
            result -= CN_NUM[xxx[i - 1]]
            result += CN_NUM[xxx[i - 1]] * 0.1
            continue
        if d == '分':
            result -= CN_NUM[xxx[i - 1]]
            result += CN_NUM[xxx[i - 1]] * 0.01
            continue
        if d in CN_NUM:
            result += CN_NUM[d]
        # 如果为单个数字直接赋值            
        elif d in CN_UNIT:
            if unit == 0:
                unit_1 = CN_UNIT[d]
        # 这里的处理主要是考虑到类似于二十三亿五千万这种数
                if result == 0:
                    result = CN_UNIT[d]
                else:
                    result *= CN_UNIT[d]
                unit = CN_UNIT[d]
                result_1 = result
            elif unit > CN_UNIT[d]:
                result -= CN_NUM[xxx[i - 1]]
                result += CN_NUM[xxx[i - 1]] * CN_UNIT[d]
                unit = CN_UNIT[d]
            elif unit <= CN_UNIT[d]:
                if (CN_UNIT[d] < unit_1) and (len(result_list) == control):
                    result_list.append(result_1)
                    result = (result - result_1) * CN_UNIT[d]
                    control += 1
                else:
                    result *= CN_UNIT[d]
                unit = CN_UNIT[d]
                if len(result_list) == control:
                    unit_1 = unit
                    result_1 = result
# 处理二十三亿五千万和壹兆零六百二十三亿五千五百万五百这种数，及时截断
        else:
            return '出现了不能匹配的中文数字，请查验'
            break
#     print('第{}步结果为{}单位为{}'.format(i + 1, result, unit))
#     print(result_list)
#     print(result)
#     print(unit_1)
    return sum(result_list) + result


test=['八',
'十一',
'一百二十三',
'一千二百零三',
'上交金额伍拾陆万柒仟零肆角',
'十万零三千六百零九',
'一百二十三万四千五百六十七',
'一千一百二十三万四千五百六十七',
'捌亿柒仟零肆拾陆万贰角捌分',
'一百零二亿五千零一万零一千零三十八',
'壹兆零六百二十三亿五千五百万五百零捌元叁角柒分'
]
test1=[
'捌亿柒仟零肆拾陆万贰角捌分'
]
for d in test1:
    result = convert_cndigit(d)
    print(f'{d}转换为阿拉伯数字为{result}')




