unit TranslateFixed;

interface
implementation
uses ComConst,Consts,DBConsts,JConsts,MidConst,
     OleConst,RTLConsts,SysConst, Windows,VDBConsts;

procedure HookResourceString(rs: PResStringRec; newStr: PChar);
var
  oldprotect : DWORD;
begin
  VirtualProtect(rs, SizeOf(rs^), PAGE_EXECUTE_READWRITE, @oldProtect);
  rs^.Identifier := integer(newStr);
  VirtualProtect(rs, SizeOf(rs^), oldProtect, @oldProtect);
end;

procedure Translate;
begin
  HookResourceString(@DBConsts.SInvalidFloatValue,'''%s'' �� � ������� ������� �������� �� ������ ''%s''');
  HookResourceString(@DBConsts.SFieldRequired , '������ ''%s'' ������ �� ��� ��������');
  HookResourceString(@DBConsts.SFieldValueError , '��������� �������� �� ������ ''%s''');
  HookResourceString(@SysConst.SInvalidFloat,'''%s'' �� � ������� ������� ��������');
  HookResourceString(@SysConst.SInvalidInteger,'''%s'' �� � ������� ����������� ��������');
  HookResourceString(@SysConst.SInvalidDate , '''%s'' �� � ������� ����');
  HookResourceString(@SysConst.SInOutError , '������/������� ������ %d');
  HookResourceString(@SysConst.SIntOverflow , '����������� ����������');
  HookResourceString(@SysConst.SInvalidOp , '��������� �������� � ������� �������');
  HookResourceString(@SysConst.SZeroDivide , '������� �� ����');
  HookResourceString(@SysConst.SOverflow , '���������� ��� ������ � ������� �������');
  HookResourceString(@Consts.SOKButton , 'OK');
  HookResourceString(@Consts.SCancelButton , '����&�');
  HookResourceString(@Consts.SYesButton , '&��');
  HookResourceString(@Consts.SNoButton , '&��');
  HookResourceString(@Consts.SHelpButton , '&�����');
  HookResourceString(@Consts.SCloseButton , '&�������');
  HookResourceString(@Consts.SIgnoreButton , '&���������');
  HookResourceString(@Consts.SRetryButton , '&������');
  HookResourceString(@Consts.SAbortButton , '��������');
  HookResourceString(@Consts.SAllButton , '&������');
  HookResourceString(@Consts.SMsgDlgWarning , '��������������');
  HookResourceString(@Consts.SMsgDlgError , '������');
  HookResourceString(@Consts.SMsgDlgInformation , '����������');
  HookResourceString(@Consts.SMsgDlgConfirm , '������������');
  HookResourceString(@Consts.SMsgDlgYes , '&��');
  HookResourceString(@Consts.SMsgDlgNo , '&��');
  HookResourceString(@Consts.SMsgDlgOK , 'OK');
  HookResourceString(@Consts.SMsgDlgCancel , '����&�');
  HookResourceString(@Consts.SMsgDlgHelp , '&�����');
  HookResourceString(@Consts.SMsgDlgHelpNone , '���� �������� �����');
  HookResourceString(@Consts.SMsgDlgHelpHelp , '�����');
  HookResourceString(@Consts.SMsgDlgAbort , '��������');
  HookResourceString(@Consts.SMsgDlgRetry , '&������');
  HookResourceString(@Consts.SMsgDlgIgnore , '&���������');
  HookResourceString(@Consts.SMsgDlgAll , '&������');
  HookResourceString(@Consts.SMsgDlgNoToAll , '�&� �� ������');
  HookResourceString(@Consts.SMsgDlgYesToAll , '�&� �� ������');
  HookResourceString(@VDBConsts.SDeleteRecordQuestion , '��������� �� ����?');
  HookResourceString(@VDBConsts.SDeleteMultipleRecordsQuestion , '��������� �� ��������� ������?');

end;

initialization
  Translate;
finalization
end.

