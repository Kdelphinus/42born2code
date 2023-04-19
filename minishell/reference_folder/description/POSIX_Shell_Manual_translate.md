- **POSIX** (IEEE Std 1003.1-2017) **Shell Manual translate** by DeepL
    
    [notion 정리](https://brassy-plate-60f.notion.site/Minishell-07bcbfdcebf949688b827bdd36940bf9)
    
    [POSIX shell manual](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_07)
    
    - **2.1 Shell Introduction**
        
        셸은 명령 언어 인터프리터입니다. 이 장에서는 POSIX.1-2017의 시스템 인터페이스 볼륨에 정의된 시스템() 및 팝엔() 함수와 sh 유틸리티에서 사용되는 명령 언어 구문에 대해 설명합니다.
        
        셸은 다음과 같은 일반적인 작업 개요에 따라 작동합니다. 구체적인 세부 사항은 이 장의 인용된 섹션에 포함되어 있습니다.
        
        셸은 파일(sh 참조), -c 옵션 또는 POSIX.1-2017의 시스템 인터페이스 볼륨에 정의된 system() 및 popen() 함수에서 입력을 읽습니다. 셸 명령 파일의 첫 줄이 "#!" 문자로 시작하면 결과가 지정되지 않은 것입니다.
        
        **셸은 입력을 토큰(단어 및 연산자)으로 분해합니다(토큰 인식 참조).**
        
        **셸은 입력을 단순 명령(단순 명령 참조) 및 복합 명령(복합 명령 참조)으로 파싱합니다.**
        
        셸은 각 명령의 여러 부분에 대해 다양한 확장을 개별적으로 수행하여 명령 및 인수로 취급할 경로 이름과 필드 목록을 생성합니다(wordexp 참조).
        
        **셸은 리디렉션을 수행하고(리디렉션 참조) 매개변수 목록에서 리디렉션 연산자 및 해당 피연산자를 제거합니다.**
        
        셸은 함수(함수 정의 명령 참조), 내장(특수 내장 유틸리티 참조), 실행 파일 또는 스크립트를 실행하여 인수의 이름을 1에서 n까지의 위치 매개변수로 지정하고 명령의 이름(스크립트 내의 함수인 경우 스크립트의 이름)을 0의 위치 매개변수로 지정합니다(명령 검색 및 실행 참조).
        
        **셸은 선택적으로 명령이 완료될 때까지 기다렸다가 종료 상태를 수집합니다(명령의 종료 상태 참조).**
        
    - **2.2 Quoting**
        - **기본 설명**
            
            Quoting은 특정 문자나 단어의 특수한 의미를 셸에서 제거하는 데 사용됩니다. Quoting는 다음 단락에서 특수 문자의 문자 그대로의 의미를 유지하고, 예약어가 그렇게 인식되지 않도록 하며, Here-document 처리 내에서 매개변수 확장 및 명령 대체를 방지하는 데 사용할 수 있습니다(Here-document 참조).
            
            The application shall quote the following characters if they are to represent themselves:
            
            ```c
            |  &  ;  <  >  (  )  $  `  \  "  '  <space>  <tab>  <newline>
            ```
            
            다양한 quoting 메커니즘에는 이스케이프 문자, 작은따옴표 및 큰따옴표가 있습니다. here-document는 다른 형태의 인용을 나타냅니다(here-document 참조).
            
            - 과제 범위를 넘어서는 내용
                
                and the following may need to be quoted under certain circumstances. That is, these characters may be special depending on conditions described elsewhere in this volume of POSIX.1-2017:
                
                ```c
                *   ?   [   #   ˜   =   %
                ```
                
        - 2.2.1 과제 범위를 벗어나는 내용
            
            2.2.1 이스케이프 문자(백슬래시)
            
            따옴표로 묶지 않은 <백슬래시>는 <새줄>을 제외하고 다음 문자의 리터럴 값을 보존합니다. <백슬래시> 다음에 <새줄>이 오는 경우 쉘은 이를 줄 연속으로 해석합니다. 입력을 토큰으로 분할하기 전에 <백슬래시>와 <새줄>을 제거해야 합니다. 이스케이프된 <새줄>은 입력에서 완전히 제거되고 공백으로 대체되지 않으므로 토큰 구분자 역할을 할 수 없습니다.
            
        - **2.2.2 Single-Quotes**
            
            문자를 작은따옴표('words')로 묶으면 작은따옴표 안에 있는 각 문자의 literal value가 보존됩니다. 작은 따옴표 안에는 작은 따옴표를 사용할 수 없습니다.
            
        - **2.2.3 Double-Quotes**
            
            큰따옴표("words")로 문자를 묶을 경우 다음과 같이 큰따옴표 안의 모든 문자(  `$  \  '`  3개의 문자는 제외)의 literal value는 그대로 유지됩니다.
            
            `$`는 매개변수 확장(매개변수 확장 참조), 명령 대체(명령 대체 참조) 및 산술 확장(산술 확장 참조)을 도입하는 특별한 의미를 유지해야 합니다.
            따옴표로 묶인 문자열 내에서 `$(`와 일치하는 `)` 사이에 포함된 입력 문자는 큰따옴표의 영향을 받지 않고, 단어가 확장될 때 출력이 "$(...)"로 대체되는 명령을 정의해야 합니다. 토큰 인식의 토큰화 규칙(별칭 치환의 별칭 치환은 포함하지 않음)은 일치하는 `)`을 찾기 위해 재귀적으로 적용되어야 합니다.
            묶은 `$(`에서 일치하는 `)`까지의 문자열 내에는 이스케이프되지 않은 큰따옴표 또는 작은따옴표가 짝수 개 포함되어야 합니다(있는 경우). 리터럴  `{`또는 `}`를 이스케이프하려면 앞의 <백슬래시> 문자를 사용해야 합니다. 매개변수 확장의 규칙을 사용하여 일치하는 `}`를 결정해야 합니다.
            
            ```는 다른 형태의 명령 대체를 소개하는 특별한 의미를 유지합니다(명령 대체 참조). 첫 번째 백따옴표와 다음 백따옴표까지의 문자 중 이스케이프 문자가 제거된 <백슬래시>가 앞에 오지 않은 인용된 문자열 부분은 해당 단어가 확장될 때 출력이 `...`로 대체되는 명령을 정의합니다. 다음 두 경우 중 하나는 정의되지 않은 결과를 생성합니다.
            "...`" 시퀀스 내에서 시작하지만 끝나지 않는 작은따옴표 또는 큰따옴표로 묶인 문자열인 경우.
            동일한 큰따옴표로 묶인 문자열 내에서 시작하지만 끝나지 않는 "`...`" 시퀀스인 경우.
            
            `\`는 특수한 경우 다음 문자 중 하나가 뒤에 올 때만 이스케이프 문자(이스케이프 문자(백슬래시) 참조)로서의 특별한 의미를 유지합니다.
            `$   `   "   \   <newline>`
            
            애플리케이션은 큰따옴표 앞에 <백슬래시>를 붙여 큰따옴표 안에 포함시켜야 합니다. 매개변수 '@'는 큰따옴표 안에 특별한 의미를 가지며 특수 매개변수 에 설명되어 있습니다.
            
    - **2.3 Token Recognition**
        - **기본 설명**
            
            쉘은 입력을 줄 단위로 읽어야 합니다. (쉘이 입력을 읽는 방법에 대한 자세한 내용은 sh 설명을 참조하세요.) 입력 줄은 길이에 제한이 없습니다. 이러한 줄은 일반 토큰 인식과 여기 문서 처리라는 두 가지 주요 모드를 사용하여 구문 분석해야 합니다.
            
            **io_here** 토큰이 문법에 의해 인식되면(셸 문법 참조), 다음 NEWLINE 토큰 바로 뒤에 오는 하나 이상의 후속 줄이 하나 이상의 여기 문서의 본문을 형성하며 여기 문서의 규칙에 따라 구문 분석되어야 합니다.
            
            **io_here**를 처리하지 않는 경우 쉘은 입력의 다음 문자에 아래의 첫 번째 적용 가능한 규칙을 적용하여 입력을 토큰으로 분할합니다. 토큰은 입력의 현재 위치에서 아래 규칙 중 하나에 따라 토큰이 구분될 때까지 토큰을 구성하는 문자는 따옴표 문자를 포함하여 입력에 있는 문자와 정확히 일치해야 합니다. 토큰이 구분되었다고 표시되었지만 토큰에 포함된 문자가 없는 경우 실제 토큰이 구분될 때까지 처리가 계속됩니다.
            
            1. 입력의 끝이 인식되면 현재 토큰(있는 경우)이 구분됩니다.
            2. 이전 문자가 연산자의 일부로 사용되었고 현재 문자가 따옴표로 묶이지 않고 이전 문자와 함께 연산자를 형성하는 데 사용될 수 있는 경우 해당 (연산자) 토큰의 일부로 사용해야 합니다.
            3. 이전 문자가 연산자의 일부로 사용되었고 현재 문자를 이전 문자와 함께 사용하여 연산자를 형성할 수 없는 경우 이전 문자가 포함된 연산자를 구분해야 합니다.
            4. 현재 문자가 `\`, `'` 또는  `"` 이고 quoted되지 않은 경우 quoted된 텍스트의 끝까지 이어지는 문자에 대한 quoting에 영향을 미칩니다. [Quoting](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_02) 규칙은 인용하기 에 설명된 대로 따릅니다. token recognition 중에는 치환(substitutions)이 실제로 수행되지 않으며, 결과 토큰(result token)에는 <quotation-mark>와 quoted text의 끝 사이에 포함되거나 둘러싸는 quotes or substitution operators를 포함하여 수정되지 않은 입력에 나타나는 문자(<newline> joining 제외)가 정확히 포함되어야 합니다. 토큰은 the quoted field의 끝으로 구분되지 않아야 합니다.
                - english
                    
                    If the current character is <backslash>, single-quote, or double-quote and it is not quoted, it shall affect quoting for subsequent characters up to the end of the quoted text. The rules for quoting are as described in [Quoting](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_02) . During token recognition no substitutions shall be actually performed, and the result token shall contain exactly the characters that appear in the input (except for <newline> joining), unmodified, including any embedded or enclosing quotes or substitution operators, between the <quotation-mark> and the end of the quoted text. The token shall not be delimited by the end of the quoted field.
                    
            5. 현재 문자가 unquoted `$` 또는 ```인 경우 쉘은 매개변수 확장([Parameter Expansion](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_02)), 명령 대체([Command Substitution](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_03)) 또는 산술 확장([Arithmetic Expansion](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_04)) 후보의 시작을 도입부의 unquoted character sequences에서 식별해야 합니다: `$` 또는 `${`, `$(` 또는 ```, `$((` 등의 각각의 경우. shell은 확장할 단위의 끝을 결정하기 위해 충분한 입력을 읽어야 합니다(the cited sections에서 설명한 대로). 문자를 처리하는 동안 치환 내에 중첩되어 있는, expansions 또는 quoting의 instances가 발견되면 shell은 발견된 구조체에 지정된 방식으로 재귀적으로 처리합니다. substitution의 시작부터 끝까지 발견된 문자는 포함된 구조를 인식하는 데 필요한 모든 재귀를 허용하며, 포함되거나 둘러싸고 있는 substitution 연산자 또는 quotes를 포함하여 결과 토큰에 수정되지 않은 상태로 포함되어야 합니다. 토큰은 substitution의 끝으로 구분되지 않아야 합니다.
            6. current character가 not quoted이고 새 연산자의 the first character로 사용될 수 있는 경우, 현재 토큰(있는 경우)을 구분되어야 합니다. current character는 다음 (연산자)토큰의 시작 문자로 사용됩니다.
            7. 현재 문자가 unquoted <blank>인 경우, 이전 문자가 포함된 토큰은 모두 구분되고 현재 문자는 삭제됩니다.
            8. previous character가 word의 일부였던 경우 현재 문자가 해당 word에 추가됩니다.
            9. 현재 문자가 `#`인 경우, 해당 문자와 다음 <newline>(\n) 까지의 모든 후속 문자는 comment(주석)으로 처리되어 넘어갑니다. 줄을 끝내는 <newline>(\n)은 comment(주석)의 일부로 간주되지 않습니다.
            10. The current character가 new word의 시작 문자로 사용됩니다.
            
            토큰이 구분되면 [Shell Grammar](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)의 문법에 따라 토큰이 분류됩니다.
            
        - **2.3.1 Alias Substitution**
            
            토큰이 구분된 후 (단, [Shell Grammar](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_10)의 문법 규칙을 적용하기 전에) 단순 명령의 명령 이름 단어로 식별되는 결과 단어를 검사하여 unquoted, valid alias name인지 확인해야 합니다. 그러나 올바른 문법 문맥에 있는 예약어는 alias substitution의 후보가 될 수 없습니다. valid alias name (see XBD [Alias Name](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html#tag_03_10))은 [alias](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/alias.html) utility에 의해 정의된 이름이어야 하며, 이후에 [unalias](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/unalias.html)을 사용하여 undefined 되면 유효하지 않습니다. Implementations는 shell이 호출될 때 사전에 정의된 valid aliases을 제공할 수도 있습니다. recursive aliasing에서 무한 루프를 방지하기 위해 shell이 현재 수정 혹은 생성하는 이름의 alias를 처리하고 있지 않은 경우에만, alias를 수정하거나 생성할 수 있으며, 그렇지 않은 경우에는 수정또는 생성되지 않아야 합니다.
            
            단어를 대체하는 alias의 value가 <blank>으로 끝나면 shell은 다음 명령어에서 alias substitution를 확인하며, 유효한 별칭이 아닌 단어가 발견되거나 별칭 값이 <blank>으로 끝나지 않을 때까지 이 프로세스를 계속합니다.
            
            POSIX.1-2017의 이 볼륨에 지정된 대로 사용할 경우, 별칭 정의는 shell의 별도 호출이나 shell에 의해 호출되는 유틸리티 실행 환경에 의해 상속되지 않습니다. see [Shell Execution Environment](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_12).
            
    - ~~2.4 Reserved Words (과제 범위를 벗어나는 내용)~~
        
        [https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18)
        
    - **2.5 Parameters and Variables**
        - 2.5.1 Positional Parameters (과제 범위를 벗어나는 내용)
        - **2.5.2 Special Parameters**
            
            ? : 가장 최근 파이프라인의 decimal exit status로 확장합니다 (see [Pipelines](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_02)).
            
            $ : 호출된 셸의 10진수 프로세스 ID로 확장됩니다. 서브셸(셸 실행 환경 참조)에서는 '$'가 현재 셸의 값과 동일한 값으로 확장됩니다.
            
            - 과제 범위를 벗어나는 내용
                
                아래에는 특수 매개변수와 해당 매개변수가 확장되는 값이 나열되어 있습니다. 특수 매개변수의 값만 나열되어 있으며, 단어 확장에 관련된 모든 단계에 대한 자세한 요약은 *[wordexp](https://pubs.opengroup.org/onlinepubs/9699919799/functions/wordexp.html#)*를 참조하세요.
                
                @ : Expands to the positional parameters, starting from one, initially producing one field for each positional parameter that is set. When the expansion occurs in a context where field splitting will be performed, any empty fields may be discarded and each of the non-empty fields shall be further split as described in [Field Splitting](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_05). When the expansion occurs within double-quotes, the behavior is unspecified unless one of the following is true:
                • Field splitting as described in [Field Splitting](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_05) would be performed if the expansion were not within double-quotes (regardless of whether field splitting would have any effect; for example, if *IFS* is null).
                • The double-quotes are within the *word* of a ${*parameter*:-*word*} or a ${*parameter*:+*word*} expansion (with or without the <colon>; see [Parameter Expansion](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_02)) which would have been subject to field splitting if *parameter* had been expanded instead of *word*.
                If one of these conditions is true, the initial fields shall be retained as separate fields, except that if the parameter being expanded was embedded within a word, the first field shall be joined with the beginning part of the original word and the last field shall be joined with the end part of the original word. In all other contexts the results of the expansion are unspecified. If there are no positional parameters, the expansion of '@' shall generate zero fields, even when '@' is within double-quotes; however, if the expansion is embedded within a word which contains one or more other parts that expand to a quoted null string, these null string(s) shall still produce an empty field, except that if the other parts are all within the same double-quotes as the '@', it is unspecified whether the result is zero fields or one empty field.
                
                * : Expands to the positional parameters, starting from one, initially producing one field for each positional parameter that is set. When the expansion occurs in a context where field splitting will be performed, any empty fields may be discarded and each of the non-empty fields shall be further split as described in [Field Splitting](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_06_05). When the expansion occurs in a context where field splitting will not be performed, the initial fields shall be joined to form a single field with the value of each parameter separated by the first character of the *IFS* variable if *IFS* contains at least one character, or separated by a <space> if *IFS* is unset, or with no separation if *IFS* is set to a null string.
                
                # : Expands to the decimal number of positional parameters. The command name (parameter 0) shall not be counted in the number given by '#' because it is a special parameter, not a positional parameter.
                
                ? : Expands to the decimal exit status of the most recent pipeline (see [Pipelines](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_02)).
                
                - : Expands to the current option flags (the single-letter option names concatenated into a string) as specified on invocation, by the *[set](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#set)* special built-in command, or implicitly by the shell.
                
                $ : Expands to the decimal process ID of the invoked shell. In a subshell (see [Shell Execution Environment](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_12) ), '$' shall expand to the same value as that of the current shell.
                
                ! : Expands to the decimal process ID of the most recent background command (see [Lists](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_03)) executed from the current shell. (For example, background commands executed from subshells do not affect the value of "$!" in the current shell environment.) For a pipeline, the process ID is that of the last command in the pipeline.
                
                0 : (Zero.) Expands to the name of the shell or shell script. See *[sh](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/sh.html#)* for a detailed description of how this name is derived.
                
                See the description of the *IFS* variable in [Shell Variables](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_05_03).
                
        - **2.5.3 Shell Variables**
            
            변수는 환경으로부터 초기화되어야 하며(POSIX.1-2017의 시스템 인터페이스 볼륨에 있는 [XBD 환경 변수](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap08.html#tag_08) 및 *exec* function에 정의된 대로), 변수 할당 명령으로 새 값을 지정할 수 있습니다. 변수가 environment에서 initialized되면 즉시 be marked for export되어야 합니다.(the *[export](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#export)* special built-in 참조). 새 변수는 변수 할당을 통해 정의하고 초기화할 수 있으며, the *[read](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/read.html)* or *[getopts](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/getopts.html)* utilities, for 루프에서 *name* 매개변수, ${name= word} 확장 또는 구현 확장으로 제공되는 다른 메커니즘을 사용하여 초기화할 수 있습니다.
            
            다음 변수는 셸 실행에 영향을 줍니다.
            
            ENV : 시스템이 User Portability Utilities option을 지원하는 경우 *ENV* shell variable의 처리가 지원되어야 합니다. 이 변수는 대화형 셸이 호출될 때만 셸에 의해 매개변수 확장(매개변수 확장 참조)이 적용되며, 그 결과 값은 현재 환경에서 실행할 셸 명령이 포함된 파일의 경로명으로 사용됩니다. 이 파일은 실행 가능하지 않아도 됩니다. ENV의 확장 값이 절대 경로명이 아닌 경우 결과는 지정되지 않습니다. 사용자의 실제 및 유효 사용자 ID 또는 실제 및 유효 그룹 ID가 다른 경우 ENV는 무시됩니다.
            
            PATH : 명령 해석에 영향을 주는 데 사용되는 XBD 환경 변수에 설명된 대로 형식이 지정된 문자열입니다(명령 검색 및 실행 참조).
            
            PWD : shell과 cd 유틸리티로 설정합니다. 셸에서 이 값은 다음과 같이 환경으로부터 초기화됩니다. 
            실행될 때에는 PWD 값이 environment의 shell에 전달되며, 값이 terminating null byte를 포함하여 {PATH_MAX} 바이트보다 길지 않은 current working directory의 absolute pathname이고 값에 점 또는 점-점 구성 요소가 포함되어 있지 않은 경우 셸은 PWD를 환경의 값으로 설정합니다.
            그렇지 않으면 실행될 때에는 PWD 값이 environment의 shell에 전달되며, 값이 현재 작업 디렉터리의 절대 경로 이름이면서 동시에 값에 점 또는 점-점인 구성 요소가 포함되지 않은 경우일때, shell이 PWD를 환경의 값으로 설정할지 아니면 pwd -P로 출력되는 경로 이름으로 설정할지 지정되지 않습니다. 
            그외에는, sh 유틸리티는 PWD를 pwd -P로 출력되는 경로명으로 설정합니다. PWD가 환경의 값으로 설정된 경우, 이 값에는 심볼릭 링크 유형의 파일을 참조하는 구성 요소가 포함될 수 있습니다. PWD가 pwd -P에 의해 출력되는 경로명으로 설정된 경우 현재 작업 디렉터리 또는 해당 디렉터리의 상위 디렉터리에 대한 권한이 충분하지 않아 해당 경로명을 결정할 수 없는 경우 PWD 값이 지정되지 않습니다. 이 변수에 대한 할당은 무시될 수 있습니다. 애플리케이션에서 PWD 값을 설정하거나 설정 해제하면 cd 및 pwd 유틸리티의 동작이 지정되지 않습니다.
            
    - ~~2.6 Word Expansions (과제 범위를 벗어나는 내용)~~
    - **2.7 Redirection**
        - 기본 설명
            
            리디렉션은 current shell execution environment([Shell Execution Environment](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_12) 참조) 또는 모든 명령에 대한 파일을 열고 닫는 데 사용됩니다. 리디렉션 연산자는 아래에 설명된 대로 파일 설명자를 나타내는 숫자와 함께 사용할 수 있습니다(XBD *[File Descriptor](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html#tag_03_166)* 참조).
            
            리디렉션에 사용되는 전체 형식은 다음과 같습니다:
            
            [n] redir-op(<, <<, >, >>) word
            숫자 n은 파일 설명자 번호를 지정하는 선택적 십진수이며, 애플리케이션은 이 숫자가 앞의 텍스트와 구분되어야 하고 리디렉션 연산자 redir-op 바로 앞에 오도록 해야 합니다. **n이 따옴표로 묶여 있으면 이 숫자는 리디렉션 표현식의 일부로 인식되지 않습니다.** 예를 들면 다음과 같습니다:
            
            echo \2 > a
            
            는 문자 2를 파일 a에 씁니다. redir-op의 일부가 따옴표로 묶여 있으면 리디렉션 표현식이 인식되지 않습니다. 예
            
            echo 2\> a
            
            는 2>a 문자를 표준 출력에 씁니다. 선택적 숫자, 리디렉션 연산자 및 단어는 실행할 명령에 제공된 인수(있는 경우)에 나타나지 않아야 합니다.
            
            열린 파일은 0으로 시작하는 10진수로 표시됩니다. 가능한 가장 큰 값은 구현에 따라 정의되지만, 모든 구현은 애플리케이션에서 사용할 수 있도록 최소 0에서 9까지를 지원해야 합니다. 이러한 숫자를 "file descriptors"라고 합니다. 값 0, 1 및 2는 특별한 의미와 통상적인 용도를 가지며 특정 리디렉션 연산에 의해 암시되며 각각 표준 입력, 표준 출력 및 표준 오류라고 합니다. 프로그램은 일반적으로 표준 입력에서 입력을 받고 표준 출력에 출력을 씁니다. 오류 메시지는 일반적으로 표준 오류에 기록됩니다. 리디렉션 연산자 앞에는 파일 설명자 번호를 지정하기 위해 하나 이상의 숫자(중간 <공백> 문자는 허용되지 않음)를 넣을 수 있습니다.
            
            리디렉션 연산자가 **"<<" 또는 "<<-"인 경우 리디렉션 연산자 뒤에 오는 단어는 따옴표가 제거**되며, 다른 확장이 발생하는지 여부는 지정되지 않습니다. **다른 리디렉션 연산자의 경우 리디렉션 연산자 뒤에 오는 단어는 물결표 확장, 매개변수 확장, 명령 대체, 산술 확장 및 따옴표 제거를 적용해야 합니다.** 경로명 확장은 비대화형 셸에 의해 단어에 대해 수행되어서는 안 되며, 대화형 셸은 확장을 수행할 수 있지만 확장으로 인해 하나의 단어가 될 때만 수행해야 합니다.
            
            명령에 리디렉션 연산자가 두 개 이상 지정되어 있는 경우 the order of evaluation는 from beginning to end.
            
            **파일을 열거나 만들지 못하면 리디렉션이 실패합니다.**
            
        - **2.7.1 Redirecting Input**
            
            입력 리디렉션은 **the file** whose name results from the expansion of *word*에서 읽을 수 있도록 파일을 열거나 file descriptor가 지정되지 않은 경우 표준 입력을 열도록 합니다.
            
            입력 리디렉션의 일반적인 형식은 다음과 같습니다:
            
            ```jsx
            [n] < word
            ```
            
            여기서 선택 사항인 n은 파일 기술자 번호를 나타냅니다. 번호가 생략된 경우 리디렉션은 표준 입력(파일 기술자 0)을 참조합니다.
            
        - **2.7.2 Redirecting Output**
            
            출력을 리디렉션하는 두 가지 일반적인 형식은 다음과 같습니다:
            
            ```jsx
            [n] > word
            ~~[n] >| word~~
            ```
            
            여기서 선택 사항인 n은 file descriptor 번호를 나타냅니다. 번호가 생략된 경우 리디렉션은 표준 출력(file descriptor 1)을 참조합니다.
            
            '>' 형식을 사용한 출력 리디렉션은 ~~*noclobber* 옵션이 설정되어 있고(설정 -C에 대한 설명 참조) 단어의 확장자로 명명된 파일이 존재하고 일반 파일인 경우 실패합니다. 그렇지 않으면~~ '>' ~~또는 ">|"~~ 형식을 사용하여 리디렉션하면 단어 확장으로 이름이 지정된 파일이 생성되어 지정된 파일 설명자(지정되지 않은 경우 표준 출력)로 출력되도록 열리게 됩니다. 파일이 존재하지 않는 경우 **파일을 생성**하고, 그렇지 않은 경우 파일을 연 후 be truncated **to be an empty file**.
            
        - **2.7.3 Appending Redirected Output**
            
            Appended output redirection은 **the file** whose name results from the expansion of word을 지정된 file descriptor에서 출력하기 위해 open합니다. 파일은 [open()](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html) 함수가 O_APPEND 플래그와 함께 호출된 것처럼 열립니다. 파일이 존재하지 않으면 파일을 생성합니다.
            
            appending redirected output의 일반적인 형식은 다음과 같습니다:
            
            ```jsx
            [n] >> word
            ```
            
            여기서 선택적 n은 file descriptor 번호를 나타냅니다. 번호가 생략된 경우 리디렉션은 표준 출력(파일 기술자 1)을 참조합니다.
            
        - **2.7.4 Here-Document**
            
            리디렉션 연산자 "<<" 및 "<<-"는 모두 셸에서 읽은 후속 줄을 명령 입력으로 리디렉션할 수 있습니다. 리디렉션된 줄을 "here-document"라고 합니다.
            
            here-document는 다음 <newline> 다음에 시작하여 delimiter 및 <newline>만 포함된 줄이 있을 때까지 계속되고 그 사이에 <공백> 문자가 없는 단일 단어로 취급됩니다. Then the next here-document starts, if there is one. 형식은 다음과 같습니다:
            
            ```
            [n] << word
                here-document
            delimiter
            ```
            
            여기서 선택 사항인 n은 file descriptor 번호를 나타냅니다. 번호를 생략하면 여기 문서는 표준 입력(파일 기술자 0)을 참조합니다. file descriptor가 일반 파일, 특수 파일 또는 파이프로 열리는지 여부는 지정되지 않습니다. Portable applications cannot rely on the file descriptor being seekable (see XSH *[lseek](https://pubs.opengroup.org/onlinepubs/9699919799/functions/lseek.html#)*).
            
            word의 일부가 따옴표로 묶이지 않은 경우 parameter expansion, 명령 대체 및 산술 확장을 위해 여기 문서의 모든 줄을 확장해야 합니다.그렇지 않으면 구분 기호는 단어 자체가 됩니다.
            
            단어의 일부가 따옴표로 묶이지 않은 경우 매개변수 확장, command substitution과 arithmetic expansion을 위해 here-document의 모든 줄을 확장(expand)해야 합니다. 이 경우 입력의 <백슬래시>는 큰따옴표 안의 <백슬래시>처럼 동작합니다([Double-Quotes](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_02_03) 참조). 그러나 큰따옴표 문자( `"` )는 `"$()"`,  `"''"` 또는 `"${}"` 안에 큰따옴표가 나타나는 경우를 제외하고는 here-document 내에서 특별히 취급되지 않습니다.
            
            ~~리디렉션 연산자가 "<<-"인 경우 입력 줄과 후행 구분 기호가 포함된 줄에서 선행 <탭> 문자를 모두 제거해야 합니다~~. 한 줄에 "<<" ~~또는 "<<-"~~ 연산자가 두 개 이상 지정된 경우, 첫 번째 연산자와 관련된 here-document가 응용 프로그램에서 먼저 제공되어야 하며 shell에서 먼저 읽어야 합니다.
            
            터미널 장치에서  here-document를 읽고 shell이 대화형인 경우, shell은 구분 기호가 인식될 때까지 각 입력 줄을 읽기 전에 [Shell Variables](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_05_03)에 설명된 대로 처리된 변수 PS2의 내용을 표준 오류에 기록해야 합니다.
            
        - ~~2.7.5 Duplicating an Input File Descriptor  (과제 범위를 벗어나는 내용)~~
        - ~~2.7.6 Duplicating an Output File Descriptor  (과제 범위를 벗어나는 내용)~~
        - ~~2.7.7 Open File Descriptors for Reading and Writing  (과제 범위를 벗어나는 내용)~~
    - **2.8 Exit Status and Errors**
        - **2.8.1 Consequences of Shell Errors**
            
            특정 오류가 발생하면 Shell은 다음 표와 같이 표준 오류에 진단 메시지를 작성하고 종료합니다:
            
            | Error | Interactive Shell | Shell Diagnostic Message Required |
            | --- | --- | --- |
            | Shell language syntax error | shall not exit | yes |
            | Special built-in utility error | shall not exit | no |
            | Other utility (not a specialbuilt-in) error | shall not exit | no |
            | Redirection error withspecial built-in utilities | shall not exit | yes |
            | Redirection error withcompound commands | shall not exit | yes |
            | Redirection error withfunction execution | shall not exit | yes |
            | Redirection error with otherutilities (not special built-ins) | shall not exit | yes |
            | Variable assignment error | shall not exit | yes |
            | Expansion error | shall not exit | yes |
            | Command not found | shall not exit | yes |
            
            참고:
            special built-in은 shell의 일부이지만 special built-in으로 작성된 진단 메시지는 shell 진단 메시지로 간주되지 않으며 다른 유틸리티와 마찬가지로 리디렉션될 수 있습니다.
            
            shell이 진단 메시지를 작성할 필요는 없지만 필요한 경우 유틸리티 자체에서 진단 메시지를 작성해야 합니다.
            
            expansion error는 [wordexp](https://pubs.opengroup.org/onlinepubs/9699919799/functions/wordexp.html#)에 정의된 shell 확장이 수행될 때 발생하는 오류입니다(예: '!'는 유효한 연산자가 아니므로 "${x!y}"); 구현은 expansion 중에가 아니라 tokenization 중에 이를 감지할 수 있는 경우 syntax errors로 처리할 수 있습니다.
            
            subshell environment에서 "shall exit" or "may exit”로 표시된 오류가 발생하면 shell은 각각 0이 아닌 상태로 subshell environment에서 종료하고 해당 subshell environment이 호출된 환경에서 계속 진행합니다.
            
            interactive shell이 종료되지 않아야 하는 표에 표시된 모든 경우에 shell은 오류가 발생한 명령에 대한 추가 처리를 수행하지 않아야 합니다.
            
        - **2.8.2 Exit Status for Commands**
            
            각 명령에는 다른 shell commands의 동작에 영향을 줄 수 있는 exit status가 있습니다. 유틸리티가 아닌 명령의 종료 상태는 이 섹션에 설명되어 있습니다. 표준 유틸리티의 종료 상태는 해당 섹션에 설명되어 있습니다.
            
            **command를 찾을 수 없는 경우 종료 상태는 127이 됩니다.
            명령 이름을 찾았지만 실행 가능한 유틸리티가 아닌 경우 종료 상태는 126이 됩니다.** 
            셸을 사용하지 않고 유틸리티를 호출하는 애플리케이션은 이러한 종료 상태 값을 사용하여 유사한 오류를 보고해야 합니다.
            
            **word expansion 또는 redirection 중에 명령이 실패하는 경우, 종료 상태는 1에서 125 사이가 됩니다.**
            
            내부적으로, 명령이 0이 아닌 종료 상태로 종료되는지 여부를 결정하기 위해 shell은 명령에 대해 검색된 **전체 상태 값을 wait() 함수 WEXITSTATUS 매크로에 해당하는 값으로 인식해야 합니다.** 특수 매개변수 '?'를 사용하여 종료 상태를 보고할 때 shell은 사용 가능한 종료 상태의 전체 8비트를 보고해야 합니다. **signal를 수신하여 종료된 명령의 종료 상태는 128보다 큰 값으로 보고해야 합니다.**
            
    - **2.9 Shell Commands**
        - 기본 설명
        - **2.9.1 Simple Commands**
        - **2.9.2 Pipelines**
        - **2.9.3 Lists**
        - **2.9.4 Compound Commands**
        - **2.9.5 Function Definition Command**
    - **2.10. Shell Grammar**
        
        다음 문법은 셸 명령 언어를 정의합니다. 이 공식 구문은 앞의 텍스트 구문 설명보다 우선합니다.
        
        - **2.10.1 Shell Grammar Lexical Conventions**
            
            셸에 입력되는 언어는 먼저 문자 수준에서 인식되어야 합니다. 결과 토큰은 다음 규칙(순서대로 적용)에 따라 즉각적인 context에 따라 분류되어야 합니다. 이러한 규칙은 토큰 수준에서 구문 분석의 대상이 되는 "토큰"이 무엇인지 결정하는 데 사용됩니다. 토큰 인식의 토큰 인식 규칙이 적용됩니다.
            
            1. 토큰이 operator인 경우 해당 operator에 대한 토큰 식별자가 도출됩니다.
            2. 문자열이 숫자로만 구성되고 구분 문자가 '<' 또는 '>' 중 하나인 경우 토큰 식별자 IO_NUMBER가 반환됩니다.
            3. 그렇지 않으면 토큰 식별자 TOKEN이 반환됩니다.
            
            토큰에 대한 추가 구분은 문맥에 따라 다릅니다. 문맥에 따라 동일한 TOKEN이 단어, 이름, ASSIGNMENT_WORD 또는 아래의 예약어 중 하나를 산출할 수 있습니다. 아래 문법의 일부 생산물에는 다음 목록의 규칙 번호가 주석으로 표시되어 있습니다. 이러한 주석이 달린 프로덕션 중 하나를 사용하여 기호를 줄일 수 있는 토큰이 발견되면 해당 규칙을 적용하여 해당 토큰의 토큰 식별자 유형을 문법의 해당 지점에서 허용되는 토큰 식별자로 변환해야 합니다. 그런 다음 적용된 규칙에 의해 산출된 토큰 식별자 유형에 따라 축소가 진행됩니다. 두 개 이상의 규칙이 적용되는 경우, 가장 높은 번호의 규칙이 적용됩니다(다른 규칙을 참조할 수 있음). (규칙 7을 제외하고 토큰에 '='가 있으면 아무런 영향을 미치지 않습니다.)
            
            단어 토큰은 명령이 파싱되는 시점이 아니라 관련 명령이 실행되기 직전에 단어 확장 규칙이 적용되어야 합니다.
            
        - **2.10.2 Shell Grammar Rules**
            1. [Command Name]
                
                TOKEN이 정확히 예약어인 경우 해당 예약어의 토큰 식별자가 반환됩니다. 그렇지 않으면 토큰 WORD가 반환됩니다. 또한 구문 분석기가 예약어만 다음 올바른 토큰이 될 수 있는 상태인 경우에도 위와 같이 진행합니다.
                
                참고:
                
                이 시점에서는 <따옴표> 문자가 토큰에 유지되므로 따옴표로 묶인 문자열은 예약어로 인식할 수 없습니다. 이 규칙은 또한 <새줄> 또는 <세미콜론> 뒤와 같은 입력의 특정 위치를 제외하고는 예약어가 인식되지 않는다는 것을 의미하며, 문법은 예약어가 의도된 경우 사용자가 적절하게 구분했다고 가정하고 해당 요구 사항을 직접 반영하려고 시도하지 않습니다. 또한 이스케이프 문자(백슬래시)에 설명된 대로 줄 결합은 토큰화 전에 수행되므로 이스케이프된 <새줄> 문자는 이 시점에서 이미 제거됩니다.
                
                규칙 1은 문법에서 직접 참조되지 않지만 다른 규칙에서 참조되거나 전역적으로 적용됩니다.
                
            2. [Redirection to or from filename]
                
                [Redirection](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_07)에 지정된 확장이 발생합니다. 여기에 지정된 대로 정확히 하나의 필드가 생성될 수 있으며(또는 결과가 지정되지 않음), 경로 이름 확장에 대한 추가 요구 사항이 있습니다.
                
            3. [Redirection from here-document]
                
                따옴표 제거는 다음 <새줄> 이후에 시작되는 여기 문서의 끝을 찾는 데 사용되는 구분 기호를 결정하기 위해 단어에 적용됩니다.
                
            4. [Case statement termination]
                
                TOKEN이 예약어 esac과 정확히 일치하면 esac에 대한 토큰 식별자가 반환됩니다. 그렇지 않으면 토큰 WORD가 반환됩니다.
                
            5. [ **NAME** in **for ]**
                
                토큰이 이름에 대한 요건을 충족하면(XBD 이름 참조), 토큰 식별자 NAME이 반환됩니다. 그렇지 않으면 토큰 WORD가 반환됩니다.
                
            6. [Third word of **for** and **case**]
                1. [ **case** only]
                    
                    TOKEN이 예약어 in과 정확히 일치하면 in에 대한 토큰 식별자가 반환됩니다. 그렇지 않으면 토큰 WORD가 반환됩니다.
                    
                2. [ **for** only]
                    
                    토큰이 예약어 in 또는 do와 정확히 일치하는 경우, 각각 in 또는 do에 대한 토큰 식별자가 반환됩니다. 그렇지 않으면 토큰 WORD가 반환됩니다.
                    
                
                (a. 및 b.의 경우: 문법에 표시된 대로 줄 바꿈이 in 및 do 토큰 앞에옵니다. 지정된 위치에 <새줄> 문자가 있는 경우, 그 뒤에 오는 토큰이 이러한 방식으로 처리됩니다).
                
            7. [Assignment preceding command name]
                1. [When the first word]
                    
                    토큰에 '=' 문자가 포함되지 않은 경우 규칙 1이 적용됩니다. 그렇지 않으면 7b가 적용됩니다.
                    
                2. [Not the first word]
                    
                    토큰에 따옴표로 묶이지 않은(토큰 인식의 규칙 4를 적용할 때 결정됨) <등호> 문자가 포함된 경우(토큰 인식의 규칙 5를 적용할 때 결정됨) 내장된 매개변수 확장, 명령 치환 또는 산술 확장 구조의 일부가 아닌 경우입니다:
                    
                    토큰이 '='로 시작하면 규칙 1을 적용합니다.
                    
                    첫 번째 <등호> 앞에 오는 TOKEN의 모든 문자가 유효한 이름을 형성하는 경우(XBD 이름 참조), 토큰 ASSIGNMENT_WORD가 반환됩니다.
                    
                    그렇지 않으면 규칙 1이 적용될지 또는 ASSIGNMENT_WORD가 반환될지는 지정되지 않습니다.
                    
                    그렇지 않으면 규칙 1을 적용합니다.
                    
                
                반환된 ASSIGNMENT_WORD 토큰 내의 이름에 대한 할당은 [Simple Commands](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_01)에 지정된 대로 수행됩니다.
                
            8. [ **NAME** in function]
                
                토큰이 정확히 예약어인 경우, 해당 예약어의 토큰 식별자가 생성됩니다. 그렇지 않은 경우, 토큰이 이름에 대한 요구 사항을 충족하면 토큰 식별자 NAME이 생성됩니다. 그렇지 않으면 규칙 7이 적용됩니다.
                
            9. [Body of function]
                
                단어 확장 및 할당은 위의 규칙에 의해 요구되는 경우에도 이 규칙이 구문 분석 중일 때는 절대 발생하지 않습니다. 확장되거나 할당이 적용될 수 있는 각 토큰은 대신 [Token Recognition](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_03)에 설명된 토큰과 정확히 일치하는 문자로만 구성된 단일 단어로 반환되어야 합니다.
                
        - example
            
            ```
            /* -------------------------------------------------------
               The grammar symbols
               ------------------------------------------------------- */
            %token  WORD
            %token  ASSIGNMENT_WORD
            %token  NAME
            %token  NEWLINE
            %token  IO_NUMBER
            
            /* The following are the operators (see XBDOperator)
               containing more than one character. */
            
            ```
            
            ```
            
            %token  AND_IF    OR_IF    DSEMI
            /*      '&&'      '||'     ';;'    */
            
            %token  DLESS  DGREAT  LESSAND  GREATAND  LESSGREAT  DLESSDASH
            /*      '<<'   '>>'    '<&'     '>&'      '<>'       '<<-'   */
            
            %token  CLOBBER
            /*      '>|'   */
            
            /* The following are the reserved words. */
            
            %token  If    Then    Else    Elif    Fi    Do    Done
            /*      'if'  'then'  'else'  'elif'  'fi'  'do'  'done'   */
            
            %token  Case    Esac    While    Until    For
            /*      'case'  'esac'  'while'  'until'  'for'   */
            
            /* These are reserved words, not operator tokens, and are
               recognized when reserved words are recognized. */
            
            %token  Lbrace    Rbrace    Bang
            /*      '{'       '}'       '!'   */
            
            %token  In
            /*      'in'   */
            
            /* -------------------------------------------------------
               The Grammar
               ------------------------------------------------------- */
            %start program
            %%
            program          : linebreak complete_commands linebreak
                             | linebreak
                             ;
            complete_commands: complete_commands newline_list complete_command
                             |                                complete_command
                             ;
            complete_command : list separator_op
                             | list
                             ;
            list             : list separator_op and_or
                             |                   and_or
                             ;
            and_or           :                         pipeline
                             | and_or AND_IF linebreak pipeline
                             | and_or OR_IF  linebreak pipeline
                             ;
            pipeline         :      pipe_sequence
                             | Bang pipe_sequence
                             ;
            pipe_sequence    :                             command
                             | pipe_sequence '|' linebreak command
                             ;
            command          : simple_command
                             | compound_command
                             | compound_command redirect_list
                             | function_definition
                             ;
            compound_command : brace_group
                             | subshell
                             | for_clause
                             | case_clause
                             | if_clause
                             | while_clause
                             | until_clause
                             ;
            subshell         : '(' compound_list ')'
                             ;
            compound_list    : linebreak term
                             | linebreak term separator
                             ;
            term             : term separator and_or
                             |                and_or
                             ;
            for_clause       : For name                                      do_group
                             | For name                       sequential_sep do_group
                             | For name linebreak in          sequential_sep do_group
                             | For name linebreak in wordlist sequential_sep do_group
                             ;
            name             : NAME                     /* Apply rule 5 */
                             ;
            in               : In                       /* Apply rule 6 */
                             ;
            wordlist         : wordlist WORD
                             |          WORD
                             ;
            case_clause      : Case WORD linebreak in linebreak case_list    Esac
                             | Case WORD linebreak in linebreak case_list_ns Esac
                             | Case WORD linebreak in linebreak              Esac
                             ;
            case_list_ns     : case_list case_item_ns
                             |           case_item_ns
                             ;
            case_list        : case_list case_item
                             |           case_item
                             ;
            case_item_ns     :     pattern ')' linebreak
                             |     pattern ')' compound_list
                             | '(' pattern ')' linebreak
                             | '(' pattern ')' compound_list
                             ;
            case_item        :     pattern ')' linebreak     DSEMI linebreak
                             |     pattern ')' compound_list DSEMI linebreak
                             | '(' pattern ')' linebreak     DSEMI linebreak
                             | '(' pattern ')' compound_list DSEMI linebreak
                             ;
            pattern          :             WORD         /* Apply rule 4 */
                             | pattern '|' WORD         /* Do not apply rule 4 */
                             ;
            if_clause        : If compound_list Then compound_list else_part Fi
                             | If compound_list Then compound_list           Fi
                             ;
            else_part        : Elif compound_list Then compound_list
                             | Elif compound_list Then compound_list else_part
                             | Else compound_list
                             ;
            while_clause     : While compound_list do_group
                             ;
            until_clause     : Until compound_list do_group
                             ;
            function_definition : fname '(' ')' linebreak function_body
                             ;
            function_body    : compound_command                /* Apply rule 9 */
                             | compound_command redirect_list  /* Apply rule 9 */
                             ;
            fname            : NAME                            /* Apply rule 8 */
                             ;
            brace_group      : Lbrace compound_list Rbrace
                             ;
            do_group         : Do compound_list Done           /* Apply rule 6 */
                             ;
            simple_command   : cmd_prefix cmd_word cmd_suffix
                             | cmd_prefix cmd_word
                             | cmd_prefix
                             | cmd_name cmd_suffix
                             | cmd_name
                             ;
            cmd_name         : WORD                   /* Apply rule 7a */
                             ;
            cmd_word         : WORD                   /* Apply rule 7b */
                             ;
            cmd_prefix       :            io_redirect
                             | cmd_prefix io_redirect
                             |            ASSIGNMENT_WORD
                             | cmd_prefix ASSIGNMENT_WORD
                             ;
            cmd_suffix       :            io_redirect
                             | cmd_suffix io_redirect
                             |            WORD
                             | cmd_suffix WORD
                             ;
            redirect_list    :               io_redirect
                             | redirect_list io_redirect
                             ;
            io_redirect      :           io_file
                             | IO_NUMBER io_file
                             |           io_here
                             | IO_NUMBER io_here
                             ;
            io_file          : '<'       filename
                             | LESSAND   filename
                             | '>'       filename
                             | GREATAND  filename
                             | DGREAT    filename
                             | LESSGREAT filename
                             | CLOBBER   filename
                             ;
            filename         : WORD                      /* Apply rule 2 */
                             ;
            io_here          : DLESS     here_end
                             | DLESSDASH here_end
                             ;
            here_end         : WORD                      /* Apply rule 3 */
                             ;
            newline_list     :              NEWLINE
                             | newline_list NEWLINE
                             ;
            linebreak        : newline_list
                             | /* empty */
                             ;
            separator_op     : '&'
                             | ';'
                             ;
            separator        : separator_op linebreak
                             | newline_list
                             ;
            sequential_sep   : ';' linebreak
                             | newline_list
                             ;
            ```
            
    - **2.11. Signals and Error Handling**
        
        shell이 비동기(asynchronous) 목록을 실행할 때 작업 제어가 비활성화되어 있으면(*[set](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#set)* **-m**에 대한 설명 참조), 목록의 명령은 shell로부터 SIGINT 및 SIGQUIT 신호에 대해 무시(SIG_IGN)의 신호 동작을 상속받아야 합니다. 다른 모든 경우, shell에 의해 실행되는 명령은 신호 액션이 *[trap](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#trap)* special built-in에 의해 수정되지 않는 한 shell이 부모로부터 상속받은 것과 동일한 신호 액션을 상속합니다 ([trap](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_28) 참조).
        
        쉘이 foreground command을 실행하는 유틸리티의 완료를 기다리는 동안 trap이 설정된 신호가 수신되면, 해당 신호와 관련된 trap은 foreground command 명령이 완료될 때까지 실행되지 않아야 합니다. shell이 *[wait](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/wait.html)* utility를 사용하여 비동기(asynchronous) 명령이 완료되기를 기다리는 동안 트랩이 설정된 신호를 수신하면 *[wait](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/wait.html)* utility가 exit status > 128로 즉시 반환되고, 그 직후 해당 신호와 연결된 트랩이 실행됩니다.
        
        연결된 트랩 동작이 있는 shell에 대해 여러 신호가 대기 중인 경우 트랩 동작의 실행 순서는 지정되지 않습니다(unspecified).
        
    - **2.12. Shell Execution Environment**
        
        shell 실행 환경은 다음과 같이 구성됩니다 :
        
        shell 호출 시 상속된 파일과 *[exec](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#exec)*에 의해 제어되는 열린 파일을 열 수 있습니다.
        
        *[cd](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/cd.html)*로 설정한 작업 디렉터리
        
        *[umask](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/umask.html)*에 의해 설정된 파일 생성 마스크
        
        [ulimit](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/ulimit.html)으로 설정된 파일 크기 제한
        
        *[trap](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#trap)*으로 설정된 현재 트랩
        
        변수 할당에 의해 설정된 shell 매개변수([set](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_25) special built-in 참조) 또는 shell이 시작될 때 shell이 상속한 시스템 인터페이스 볼륨([export](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_22) special built-in 참조)에서 설정한 shell 매개변수
        
        ~~shell 함수; 함수 정의 명령 참조~~
        
        ~~호출 시 또는 *[set](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#set)*에 의해 켜진 옵션~~
        
        이 shell 환경에 알려진 비동기 목록에 있는 마지막 명령의 프로세스 ID; [Asynchronous Lists](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_03_02)을 참조하십시오.
        
        Shell aliases; [Alias Substitution](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_03_01)를 참조하십시오.
        
    - ~~2.13. Pattern Matching Notation (과제 범위를 벗어나는 내용)~~
        
        이 섹션에서 설명하는 패턴 일치 표기법은 셸에서 일치하는 문자열에 대한 패턴을 지정하는 데 사용됩니다. 역사적으로 패턴 매칭 표기법은 XBD 정규 표현식에 설명된 정규 표현식 표기법과 관련이 있지만 약간 다릅니다. 따라서 이 패턴 일치 표기법에 대한 규칙 설명은 정규식 표기법에 대한 설명을 기반으로 하며 차이점을 설명하기 위해 수정되었습니다.
        
    - **2.14. Special Built-In Utilities**
        - **기본 설명**
            
            셸 명령어에서 다음과 같은 "특수 내장" 유틸리티가 지원되어야 합니다. 각 명령의 출력(있는 경우)은 모든 명령에서 가능한 일반적인 redirection and piping에 따라 표준 출력에 기록되어야 합니다.
            
            "내장"이라는 용어는 셸이 유틸리티를 직접 실행할 수 있으며 검색할 필요가 없음을 의미합니다. 구현자는 모든 유틸리티를 기본 제공으로 만들 수 있지만, 여기에 설명된 특수 기본 제공 유틸리티는 두 가지 측면에서 일반 기본 제공 유틸리티와 다릅니다:
            
            특수 기본 제공 유틸리티에 오류가 발생하면 해당 유틸리티를 실행하는 셸이 중단될 수 있지만 일반 기본 제공 유틸리티에 오류가 발생해도 해당 유틸리티를 실행하는 셸이 중단되지 않습니다. (대화형 및 비대화형 셸에 대한 [Consequences of Shell Errors](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_08_01)는 해당 page를 참조하십시오.) 특수 내장 유틸리티에서 오류가 발생해도 셸이 중단되지 않는 경우 종료 값은 0이 아니어야 합니다.
            
            [단순 명령](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#tag_18_09_01)에 설명된 대로 특수 내장 유틸리티를 호출하기 전의 변수 할당은 내장 완료 후에도 유효하며, 일반 내장 유틸리티나 기타 유틸리티는 그렇지 않습니다.
            
            이 섹션의 특수 내장 유틸리티는 POSIX.1-2017의 시스템 인터페이스 볼륨에 정의된 실행 함수군을 통해 액세스할 수 있는 방식으로 제공될 필요는 없습니다.
            
            일부 특수 내장 유틸리티는 XBD 유틸리티 구문 가이드라인을 준수하는 것으로 설명되어 있습니다. 그렇지 않은 경우, "--"을 버려야 할 첫 번째 인수로 인식해야 한다는 유틸리티 설명 기본값의 요구 사항이 적용되지 않으며 준수 응용 프로그램에서는 해당 인수를 사용하지 않아야 합니다.
            
        - export - set the export attribute for variables
            
            ```c
            export name[=word]...
             
            ~~export -p~~
            ```
            
            셸은 지정된 이름에 해당하는 변수에 *[export](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#export)* attribute을 부여하여 이후에 실행되는 명령의 환경에 해당 변수가 있도록 합니다. 변수 이름 뒤에 = word가 오는 경우 해당 변수의 값은 word로 설정됩니다.
            
            *[export](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#export)* 특수 내장 기능은 XBD 유틸리티 구문 가이드라인을 지원해야 합니다.
            
            ~~When -p is specified, *[export](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#export)* shall write to the standard output the names and values of all exported variables, in the following format: "export %s=%s\n", <name>, <value>~~
            
            if *name* is set, and:
            
            ```c
            "export %s\n", <name>
            ```
            
            if *name* is unset : 
            
            shell은 the proper use of quoting을 포함하여 출력 형식을 지정하여 동일한 exporting results를 얻는 명령으로 shell에 reinput하는 데 적합하도록 해야 합니다:
            
            값이 있는 Read-only variables는 재설정할 수 없습니다.
            상태가 저장된 시점과 저장된 출력이 shell에 재입력되는 시점 사이에 변수에 값이 할당된 경우 출력 당시 설정되지 않은 변수는 설정되지 않은 상태로 재설정할 필요가 없습니다.
            인수가 지정되지 않으면 결과가 지정되지 않습니다.
            
            EXIT STATUS : (    0 ) - All *name* operands were successfully exported.
            
                                      ( > 0 ) - At least one *name* could not be exported
            
            export 명령에 의해 변경된 환경 변수는 export 명령을 실행한 사용자의 로그아웃 전까지만 유효하므로 영구적으로 변경하기 위해서는 환경 변수를 정의하는 설정 파일(/etc/profile 등) 을 직접 수정해야 한다.
            
        - unset - unset values and attributes of variables and functions
            
            ```c
            unset ~~[-fv]~~ name...
            ```
            
            *name*으로 지정된 각 variable 또는 function을 unset 합니다.
            
            f나 -v가 지정되지 않은 경우 *name*은 variable를 의미하며, 해당 이름의 variable가 존재하지 않을때, 해당 이름의 함수가 있다면 설정 해제할지 여부가 지정되지 않습니다.
            
            이전에 설정되지 않은 변수나 함수를 설정 해제해도 오류로 간주되지 않으며 셸이 중단되지 않습니다.
            
            The *[unset](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#unset)* special built-in shall support XBD *[Utility Syntax Guidelines](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html#tag_12_02)*.
            
            Note that:
            
            VARIABLE=
            
            는 설정 해제된 VARIABLE과 동일하지 않습니다(예제에서는 VARIABLE이 ""로 설정되어 있음). 또한 설정 해제할 수 있는 변수가 특수 매개변수를 포함하는 것으로 잘못 해석되어서는 안 됩니다(특수 매개변수 참조).
            
        - exit - cause the shell to exit
            
            ```c
            exit ~~[n]~~
            ```
            
            The *[exit](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html#exit)* utility는 unsigned decimal integer *n*으로 지정된 종료 상태로 Shell을 현재 실행 환경에서 종료합니다. 현재 실행 환경이 subshell 환경인 경우 Shell은 지정된 종료 상태로 subshell 환경에서 종료하고 해당 하위 Shell 환경이 호출된 환경에서 계속 진행하며, 그렇지 않으면 the shell utility는 지정된 종료 상태로 종료합니다. n이 지정되었지만 그 값이 0에서 255 사이가 아닌 경우 종료 상태는 정의되지 않습니다.
            
            EXIT의 트랩은 Shell이 종료되기 전에 실행되어야 하지만, 종료 유틸리티가 해당 트랩 자체에서 호출되는 경우를 제외하고는 Shell이 즉시 종료되어야 합니다.
            
            EXIT STATUS : 종료 상태는 n이 지정되면 n이 되지만, n이 부호 없는 십진수가 아니거나 255보다 크면 동작이 지정되지 않습니다. 그렇지 않으면 이 값은 마지막으로 실행된 명령의 종료 값이며, 실행된 명령이 없으면 0이 됩니다. 트랩 동작에서 종료가 실행되는 경우 마지막 명령은 트랩 동작 직전에 실행된 명령으로 간주됩니다.
            
            다른 섹션에서 설명한 것처럼 특정 종료 상태 값은 특별한 용도로 예약되어 있으므로 애플리케이션에서 해당 용도로만 사용해야 합니다:
            
            126 : 실행할 파일을 찾았지만 실행 가능한 유틸리티가 아닙니다.
            
            127 : 실행할 유틸리티를 찾지 못했습니다.
            
            >128 : 명령이 신호에 의해 중단되었습니다.
            
            잘못된 인수 또는 알 수 없는 옵션이 주어졌을 때 종료 동작이 지정되지 않았는데, 이는 다양한 과거 구현의 관행이 다르기 때문입니다. 255보다 큰 값은 셸에 의해 잘릴 수 있으며, waitid()를 사용하여 전체 종료 값을 가져오는 상위 프로세스에서도 사용할 수 없을 수 있습니다. 사용 오류를 감지하는 구현은 0이 아닌 종료 상태를 발생시켜야 합니다(또는 셸이 대화형이고 오류로 인해 셸이 중단되지 않는 경우 "$?"에 0이 아닌 값을 저장해야 합니다). 에 0이 아닌 값을 저장하는 것이 좋지만, 역사적으로 모든 셸에서 이 작업을 수행하지는 않았습니다.
            
