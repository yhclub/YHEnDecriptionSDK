
Pod::Spec.new do |s|

  s.name         = "YHEnDecriptionSDK"
  s.version      = "2.1.2"
  s.summary      = "公司基础SDK之一"

  s.description  = "基础SDK之一，提供加密、解密、签名、验证签名。"

  s.homepage     = "https://github.com/XmYlzYhkj/YHEnDecriptionSDK"

  s.license      = "MIT"

  s.author       = { "XmYhkj" => "yhkj_xm@163.com" }

  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/XmYlzYhkj/YHEnDecriptionSDK.git", :tag => s.version.to_s }

  s.requires_arc = true
  
  s.xcconfig = { 'OTHER_LDFLAGS' => '-lstdc++' }

  s.default_subspec = 'EncryptFull'
  
  ##---------------FULL subspec------------##
  s.subspec 'EncryptFull' do |ss|
      ss.vendored_frameworks = ["Frameworks/EncryptFull/YHEnDecriptionSDK.framework"]
  end
  
    
  ##-----------EncryptAES subspec-------##
  s.subspec 'EncryptAES' do |ss|
    ss.vendored_frameworks = ["Frameworks/EncryptAES/YHEnDecriptionSDK.framework"]
    ss.pod_target_xcconfig = { 'GCC_PREPROCESSOR_DEFINITIONS' => 'YHEnDecriptionExcludingSM=1'}
  end

  
end
