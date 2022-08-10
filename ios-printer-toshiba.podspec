#
# Be sure to run `pod lib lint ios-printer-toshiba.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ios-printer-toshiba'
  s.version          = '0.1.0'
  s.summary          = 'A short description of ios-printer-toshiba.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/fsalom/ios-printer-toshiba'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'fsalom' => 'e_fsalom@mercadona.com' }
  s.source           = { :git => 'https://github.com/fsalom/ios-printer-toshiba.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '10.0'
  s.ios.frameworks = 'CFNetwork', 'ExternalAccessory'
  s.default_subspec = 'Simulator'

  s.subspec 'Simulator' do |sp|
      sp.source_files = 'ios-printer-toshiba/Simulator/**/*', 'ios-printer-toshiba/*.swift'
      sp.ios.vendored_libraries = 'ios-printer-toshiba/Simulator/libBcpIssue.a'      
      sp.xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
      sp.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
#      sp.pod_target_xcconfig = { 'VALID_ARCHS[sdk=iphonesimulator*]' => 'x86_64' }
#      sp.pod_target_xcconfig = { 'ARCHS[sdk=iphonesimulator*]' => 'x86_64' }
  end

  s.subspec 'Device' do |sp|
      sp.source_files = 'ios-printer-toshiba/Device/**/*', 'ios-printer-toshiba/*.swift'
      sp.ios.vendored_libraries = 'ios-printer-toshiba/Device/libBcpIssue.a'
  end
end
